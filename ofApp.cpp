#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(2);
	this->line.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->face.clear();
	this->line.clear();

	int radius_span = 5;
	int deg_span = 30;

	for (int deg = 0; deg < 360; deg += deg_span) {

		for (int radius = 10; radius < 600; radius += radius_span) {

			float circle_deg = deg + ofMap(radius, 30, 600, 0, 360);
			float next_ciecle_deg = deg + ofMap(radius + radius_span, 30, 600, 0, 360);

			this->face.addVertex(glm::vec3(radius * cos((circle_deg - deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));
			this->face.addVertex(glm::vec3(radius * cos((circle_deg + deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->face.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->face.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));

			this->face.addIndex(this->face.getNumVertices() - 1); this->face.addIndex(this->face.getNumVertices() - 2); this->face.addIndex(this->face.getNumVertices() - 3);
			this->face.addIndex(this->face.getNumVertices() - 1); this->face.addIndex(this->face.getNumVertices() - 3); this->face.addIndex(this->face.getNumVertices() - 4);

			ofColor color;
			color.setHsb(ofMap((radius + deg - ofGetFrameNum() * 15) % 360, 0, 360, 0, 255), 130, 255);

			this->face.addColor(color); this->face.addColor(color); this->face.addColor(color); this->face.addColor(color);

			this->line.addVertex(glm::vec3(radius * cos((circle_deg - deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));
			this->line.addVertex(glm::vec3(radius * cos((circle_deg + deg_span * 0.2) * DEG_TO_RAD), radius * sin((circle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->line.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg + deg_span * 0.2) * DEG_TO_RAD), 0));
			this->line.addVertex(glm::vec3((radius + radius_span) * cos((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), (radius + radius_span) * sin((next_ciecle_deg - deg_span * 0.2) * DEG_TO_RAD), 0));

			this->line.addIndex(this->line.getNumVertices() - 3); this->line.addIndex(this->line.getNumVertices() - 2);
			this->line.addIndex(this->line.getNumVertices() - 4); this->line.addIndex(this->line.getNumVertices() - 1);

			this->line.addColor(ofColor(0)); this->line.addColor(ofColor(0)); this->line.addColor(ofColor(0)); this->line.addColor(ofColor(0));

		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	this->face.draw();
	this->line.draw();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}