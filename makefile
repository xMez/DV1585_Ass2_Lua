parser: lex.yy.c binary.tab.o main.cc node.cc
	g++ -std=c++11 -g -ocomp binary.tab.o lex.yy.c main.cc node.cc blockthree.cc
binary.tab.o: binary.tab.cc
	g++ -std=c++11 -g -c binary.tab.cc
binary.tab.cc: binary.yy
	bison -v --report-file=report.txt binary.yy
lex.yy.c: binary.ll binary.tab.cc
	flex binary.ll
clean:
	rm -f binary.tab.* ley.yy.c* comp report.txt target* cfg.dot stack.hh
submission:
	rm -rf ass2-comp
	mkdir ass2-comp
	cp -t ass2-comp/ binary.ll binary.yy blockthree.cc blockthree.hh main.cc makefile node.cc node.hh
	tar -zcvf /home/$$USER/submission.tgz ass2-comp
	rm -rf ass2-comp
