#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <malloc.h>

int main() {
	void* p;
	p = memalign(sizeof(void *), sizeof(void *));
	assert(p != NULL && (uintptr_t)p % sizeof(void *) == 0);
	free(p);
	p = memalign(256, 1);
	assert(p != NULL && (uintptr_t)p % 256 == 0);
	free(p);
	p = memalign(256, 256);
	assert(p != NULL && (uintptr_t)p % 256 == 0);
	free(p);

	return 0;
}
