make:
	g++ src/dvector.cpp -o program

test:
	./program < data/test.in > data/hasiltest.out