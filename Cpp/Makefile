CC = "g++"
PROJECT = image-processing-comparison
SRS = cpp.cpp

LIBS = `pkg-config opencv4 --cflags --libs`

${PROJECT} : ${SRS}
	${CC} ${SRS} -o ${PROJECT} ${LIBS}