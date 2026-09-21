#include <bit>
#include <bits/ensure.h>
#include <malloc.h>
#include <mlibc/allocator.hpp>

void *memalign(size_t align, size_t size) {
	if (align < sizeof(void *))
		align = sizeof(void *);
	align = std::bit_ceil(align);
	auto p = getAllocator().allocate(size, align);
	if (!p)
		return nullptr;
	return p;
}
