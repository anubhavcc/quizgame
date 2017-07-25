TOPDIR := $(shell pwd)
TOPRPMDIR := $(TOPDIR)/build/rpmbuild
DESTDIR = $(HOMEDIR)/bin

run:	all
	cd build && ./question

all:
	mkdir -p build && cd build && \
	cmake -DCMAKE_BUILD_TYPE=Release .. && make && cd -

install:
	cp /home/dell/proj/quiz/build/play  $(TOPDIR)  && \
	cp /home/dell/proj/quiz/build/tes.bin $(TOPDIR)

clean:
	rm -rf build
