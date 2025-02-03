#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle = dlopen("libapp.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    typedef int (*add_func_t)(int, int);
    add_func_t add = (add_func_t) dlsym(handle, "add");
    if (!add) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    int result = add(3, 4);
    printf("Result: %d\n", result);

    dlclose(handle);
    return 0;
}