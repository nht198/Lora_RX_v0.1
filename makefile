lora_gateway_pi2: lora_gateway_pi2.o arduPi_pi2.o SX1272_pi2.o
	g++ -lrt -lpthread lora_gateway_pi2.o arduPi_pi2.o SX1272_pi2.o -o lora_gateway_pi2
	rm -f lora_gateway
	ln -s lora_gateway_pi2 ./lora_gateway

arduPi_pi2.o: arduPi_pi2.cpp arduPi_pi2.h
	g++ -c arduPi_pi2.cpp -o arduPi_pi2.o	

SX1272.o: SX1272.cpp SX1272.h
	g++ -c SX1272.cpp -o SX1272.o

SX1272_pi2.o: SX1272.cpp SX1272.h
	g++ -DRASPBERRY2 -c SX1272.cpp -o SX1272_pi2.o

lib: arduPi_pi2.o SX1272.o SX1272_pi2.o lora_gateway_pi2.o
