#include <MK60F12.H>

typedef struct {
	uint32_t coroutineSP; // <-- if 0, the coroutine has return;'ed
	uint32_t callerSP;		// <-- this one should never be 0
	struct Coroutine* parentCoroutine;
	uint8_t stack[1];			// <-- this is not really 1 byte. &stack[0] just marks the top of the stack.
} Coroutine;

Coroutine* CoInit(Coroutine* (*coroutineFunction)(uint32_t value, Coroutine* coroutine), uint32_t stackSizeBytes);
uint32_t CoRun(uint32_t value, Coroutine* coroutine);
uint32_t CoYield(uint32_t value, Coroutine* coroutine);
uint32_t CoKill(Coroutine* coroutine);
uint32_t CoHasFinished(Coroutine* coroutine);
void CoEnd(Coroutine* coroutine);