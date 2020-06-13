target=glut-rotating-cube

build:
	mkdir -p out
	g++ src/main.cpp -lglut -lGL -o out/${target}

run:
	./out/${target}

clear:
	rm -r out/
