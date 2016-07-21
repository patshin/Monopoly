CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = watopoly
OBJECTS = main.o AcademicBuilding.o Building.o CollectOSAP.o CoopFee.o
					GooseNesting.o GotoTims.o Gym.o NeedlesHall.o NonProperty.o
					Property.o Residence.o SLC.o TimsLine.o Tuition.o board.o
					controller.o player.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
