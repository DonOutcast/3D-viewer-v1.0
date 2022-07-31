OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lcheck
else
	FLAGS_PLATFORM = -lcheck -lsubunit -lrt -lm -lpthread -g
endif

all: clear clean build

build: s21_3D_Viewer.a

s21_3D_Viewer.a: s21_3D_Viewer.c
	$(CC) -c $(CFLAGS) s21_3D_Viewer.c
	@ar rcs s21_3D_Viewer.a s21_3D_Viewer.o

clear:
	clear

tests: s21_3D_Viewer.a
	@gcc tests.c s21_3D_Viewer.a $(FLAGS_PLATFORM) -o tests.o
	@./tests.o

gcov_report:
	@gcc --coverage s21_3D_Viewer.c tests.c $(FLAGS_PLATFORM) -o gсov_report.o
	@./gсov_report.o
	@lcov -t .s21_3D_Viewer -o s21_3D_Viewer.info -c -d .
	@genhtml -o report s21_3D_Viewer.info
	open ./report/index.html

install:
	make clean
	cd Simba && qmake && make && make clean && rm Makefile && cd ../ && mv Simba/3D_simba.app build
	

unistall:
	rm -rf build*

dvi:
	open information/info.html
	# open $(HOME)/Applications/C8_3D_Viewer_v1.0-0/src/information/info.html | open information/info.html

dist:
	# rm -rf Archive_3D_Viewer_v1.0/
	# mkdir Archive_3D_Viewer_v1.0/
	# mkdir Archive_3D_Viewer_v1.0/src
	# cp ./build/Contents/MacOS/3D_sim Archive_3D_Viewer_v1.0/src/
	# tar cvzf Archive_3D_Viewer_v1.0.tgz Archive_3D_Viewer_v1.0/
	# rm -rf Archive_3D_Viewer_v1.0/

	rm -rf Archive_3D_Viewer_v1.0/
	mkdir Archive_3D_Viewer_v1.0/
	mkdir Archive_3D_Viewer_v1.0/src
	cp ./build/Contents/MacOS/3D_simba Archive_3D_Viewer_v1.0/src/
	tar cvzf Archive_3D_Viewer_v1.0.tgz Archive_3D_Viewer_v1.0/
	rm -rf Archive_3D_Viewer_v1.0/




check:
	@cp ../materials/linters/CPPLINT.cfg ./
	@python3 ./../materials/linters/cpplint.py --extensions=c *.c
	@python3 ./../materials/linters/cpplint.py --extensions=h *.h
	@cppcheck --enable=all --suppress=missingIncludeSystem *.c
	@rm -rf CPPLINT.cfg

clean:
	@rm -rf *.a
	@rm -rf *.o
	@rm -rf *.out
	@rm -rf report
	@rm -rf *.gcda
	@rm -rf *.gcdo
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf s21_3D_Viewer.a
	@rm -rf s21_3D_Viewer.o
	@rm -rf *.tgz
	@rm -rf *.cfg

