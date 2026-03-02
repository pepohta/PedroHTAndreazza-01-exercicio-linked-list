build:
	cmake -B build
	cmake --build build

build-tests:
	cmake -B build -DBUILD_TESTS=ON
	cmake --build build

clean:
	rm -rf build/

run:
	./build/linked_list