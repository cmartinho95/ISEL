/**
 *
 * Use libvector.so loaded and linked at runtime.
 *
 **/

#include <stdio.h>
#include <dlfcn.h>

int x[] = {1, 2};
int y[] = {3, 4};
int z[2];

int main()
{
	void *handle;
	void (*addvecp)(int *, int *, int *, int);
	void (*multvecp)(int *, int *, int *, int);
	int *addcntp, *multcntp;
	
	/* Dynamically load shared library that contains addvec() */
	handle = dlopen("./libvector.so", RTLD_LAZY | RTLD_GLOBAL);
	if (handle == NULL) {
    	fprintf(stderr, "***error: %s\n", dlerror());
		return 1;
	}
	
	/* Get a pointer to the addvec() function on library we just loaded */
	*(void **)&addvecp = dlsym(handle, "addvec");
	if (addvecp == NULL) {
    	fprintf(stderr, "***error: %s\n", dlerror());
		return 1;
	}

	/* Get a pointer to the multvec() function on library we just loaded */
	*(void **)&multvecp = dlsym(handle, "multvec");
	if (multvecp == NULL) {
    	fprintf(stderr, "***error: %s\n", dlerror());
		return 1;
	}
	
	/* Get a pointer to the addcnt counter on library we just loaded */
	*(void **)&addcntp = dlsym(handle, "addcnt");
	if (addcntp == NULL) {
    	fprintf(stderr, "***error: %s\n", dlerror());
		return 1;
	}

	/* Get a pointer to the multcnt counter on library we just loaded */
	*(void **)&multcntp = dlsym(handle, "multcnt");
	if (multcntp == NULL) {
    	fprintf(stderr, "***error: %s\n", dlerror());
		return 1;
	}	
	
	/* Now we can call addvec() and multvec() through its function pointers */
	(*addvecp)(x, y, z, 2);
	printf("addvec({%d, %d}, {%d, %d}) = {%d, %d}\n", x[0], x[1], y[0], y[1], z[0], z[1]);
	(*multvecp)(x, y, z, 2);
	printf("multvec({%d, %d}, {%d, %d}) = {%d, %d}\n", x[0], x[1], y[0], y[1], z[0], z[1]);
	
	/* display counters */
	printf("addcnt: %d, multcnt: %d\n", *addcntp, *multcntp);
	
	/* Unload the shared library */
	if (dlclose(handle) < 0) {
    	fprintf(stderr, "***error: %s\n", dlerror());
    	return 1;
	}
	return 0;
}
