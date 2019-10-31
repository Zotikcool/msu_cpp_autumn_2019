#include <iostream>
#include <cstdlib>
#include <cstring>


class LinearAllocator
{
public:
    LinearAllocator(size_t maxSize){
        if (maxSize == 0){
            buf = nullptr;
        }
        else {
            buf = new char[maxSize];
        }
        totalSize = maxSize;
        shift = 0;
    }

    char* alloc(size_t size){
        char *ptr;
        if (buf == nullptr || shift + size > totalSize) {
            return nullptr;
        }
        ptr = buf + shift;
        shift += size;
        return ptr;
    }

    void reset(){
        shift = 0;
    }

    ~LinearAllocator(){
        if (buf != nullptr) {
            delete[] buf;
        }
    }

private:
    char *buf;
    unsigned long long shift;
    unsigned long long totalSize;
};

int main(int argc, char **argv) {
    char *p;
	int size;
	if (argc == 1) {
		std::cout << "Empty input." << std::endl;
		return 0;
	}
	size = std::atoi(argv[1]);
	LinearAllocator allocator(size);
	for (int i = 2; i < argc; i++) {
		if (!strcmp(argv[i], "alloc")) {
			i++;
			if (i == argc) {
				std::cout << "No argument for alloc." << std::endl;
			}
			else {
				p = allocator.alloc(std::atoi(argv[i]));
                if (p == nullptr) {
                    std::cout << "Failed to allocate required memory." << std::endl;
                }
                else {
                    std::cout << "Successful memory allocation." << std::endl;
                }
			}
		}
		else if (!strcmp(argv[i], "reset")) {
			allocator.reset();
		}
		else {
			std::cout << "Wrong input" << std::endl;
		}
	}
	std::cout << "END." << std::endl;
    return 0;
}
