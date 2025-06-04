// 예제 참고
// https://infossm.github.io/blog/2022/02/15/Intel-Intrinsics-Guide/

// g++ -ot main.cpp
#pragma GCC target("sse2") //명령의 타겟을 지정하는 전처리 구문, -msse2 컴파일 옵션 대체 가능

#include <immintrin.h> //AVX, SSE4_2 + SSE4_1 + SSSE3 + SSE3 + SSE2 + SSE + MMX
#include <iostream>
using namespace std;

alignas(16) int arr1[4] = { 1, 2, 3, 4 };
alignas(16) int arr2[4] = { 5,6,7,8 };
alignas(16) int result1[4];
alignas(16) int result2[4];

void add_naive() { //덧셈을 4번하는 방식의 함수
	result1[0] = arr1[0] + arr2[0];
	result1[1] = arr1[1] + arr2[1];
	result1[2] = arr1[2] + arr2[2];
	result1[3] = arr1[3] + arr2[3];
}

void add_simd() {
	*(__m128i*)(result2) = _mm_add_epi32(*(__m128i*)(arr1), *(__m128i*)(arr2));
}

int main() {
	add_naive();
	for (int i = 0; i < 4; i++) cout << result1[i] << ' ';

	cout << '\n';

	add_simd();
	for (int i = 0; i < 4; i++) cout << result2[i] << ' ';
}
