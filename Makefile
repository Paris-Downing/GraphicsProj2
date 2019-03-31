

build:
	g++ hello.cpp -o app -framework GLUT -framework OpenGL

run: build
	./app
