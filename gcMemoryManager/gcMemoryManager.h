//
// Created by admin on 18.01.2025.
//

#include "boehmGC/bdwgc/include/gc/gc.h"

#ifndef MYANTLRPROJECT_GC_H
#define MYANTLRPROJECT_GC_H

#endif //MYANTLRPROJECT_GC_H



class GCManager {
public:
    GCManager() { GC_INIT(); }
    void* Allocate(size_t size) { return GC_MALLOC(size); }
    void* AllocateAtomic(size_t size) { return GC_MALLOC_ATOMIC(size); }
    void Collect() { GC_gcollect(); }
};