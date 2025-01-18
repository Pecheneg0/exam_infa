.PHONY: all
all: p_9 p_11 p_12 p_13 p_1t p_12t p_20t p_10t p_6_exam p_6.1 p_6_e p_15

p_6.1 : 6.1.c 
	cc -o $@ $<
p_9 : 9.c 
	cc -o $@ $<

p_12 : 12.c
	cc -o $@ $<

p_13 : 13.c	
	cc -o $@ $<

p_1t : 1t.c
	cc -o $@ $<

p_12t : 12t.c
	cc -o $@ $<

p_20t : 20t.c
	cc -o $@ $< 

p_10t: 10t.c
	cc -o $@ $< 

p_6_exam : 6_exam.c
	cc -o $@ $<

p_6_e : 6_e.c
	cc -o $@ $<

p_15: 15.c
	cc -o $@ $<

.PHONY: clean 
clean: p_9 p_11 p_12 p_13 p_1t p_12t p_20t p_10t p_6_exam p_15
	rm -f p_9 p_11 p_12 p_13 p_1t p_12t p_20t p_10t p_6_exam p_15

