# ■ Study-Algorithm
* 해당 Repository에 있는 소스코드들에 대한 문제에 대한 저작권은 알고리즘 문제 사이트에 귀속되어 있습니다.

<p align="center">
  <img src="https://user-images.githubusercontent.com/20036523/50101184-818d8a00-0265-11e9-9d75-ebb9fa3d0740.png" width="250" height="250" />
</p>

## ★ Greatest common divisor (최대 공약수)

* 수론에서, 정수들의 공약수(公約數, 영어: common divisor)는 동시에 그들 모두의 약수인 정수다. 적어도 하나가 0이 아닌 정수들의 최대공약수(最大公約數, 문화어: 련속나눔셈; 영어: greatest common divisor, 약자 GCD)는 공약수 가운데 가장 큰 하나다. 다항식이나 환의 원소에 대해서도 정의할 수 있다.

##### ※ Greatest common divisor Source Code

```C++
/* Reculsive greatest Common Divisor - (logN) */
int GCD(int a, int b) {

	if (b == 0) { return a; }
	else { return GCD(b, a%b); }
}

/* Loop greatest Common Divisor - (logN) */
int GCD(int a, int b) {

	while (b != 0) {
		const int r = a % b;
		a = b;
		b = r;
	}

	return a;
}
```

## ★ Eratosthenes (에라토스테네스의 체)

* 수학에서 에라토스테네스의 체는 소수를 찾는 방법이다. 고대 그리스 수학자 에라토스테네스가 발견하였다.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif" />
</p>

1. 2부터 소수를 구하고자 하는 구간의 모든 수를 나열한다. 그림에서 회색 사각형으로 두른 수들이 여기에 해당한다.

2. 2는 소수이므로 오른쪽에 2를 쓴다. (빨간색)

3. 자기 자신을 제외한 2의 배수를 모두 지운다.

4. 남아있는 수 가운데 3은 소수이므로 오른쪽에 3을 쓴다. (초록색)

5. 자기 자신을 제외한 3의 배수를 모두 지운다.

6. 남아있는 수 가운데 5는 소수이므로 오른쪽에 5를 쓴다. (파란색)

7. 자기 자신을 제외한 5의 배수를 모두 지운다.

8. 남아있는 수 가운데 7은 소수이므로 오른쪽에 7을 쓴다. (노란색)

9. 자기 자신을 제외한 7의 배수를 모두 지운다.

10. 위의 과정을 반복하면 구하는 구간의 모든 소수가 남는다.

##### ※ Eratosthenes Source Code

```C++
/* Sieve of Eratoshenes */
void SoE(const int n, const int m) {

  int pn = 0; // 소수의 개수

  vector<int>	prime; // 소수 저장
  vector<bool> check = vector<bool>(n + 1, false); // 소수 확인

	for (long long ii = 2; ii <= n; ii++) {

		if (check.at(ii) == false) {
			pn++;
			prime.push_back(ii);

			for (long long jj = ii * ii; jj <= n; jj += ii) {
				check[jj] = true;
			}
		}
	}
}
```

## ★ 골드바흐의 추측 (Goldbach's conjecture)

* 골드바흐의 추측(Goldbach's conjecture)은 오래전부터 알려진 정수론의 미해결 문제로, 2보다 큰 모든 짝수는 두 개의 소수(Prime number)의 합으로 표시할 수 있다는 것이다. 이때 하나의 소수를 두 번 사용하는 것은 허용한다.

<p align="center">
	<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/02/Goldbach_partitions_of_the_even_integers_from_4_to_50_rev4b.svg/500px-Goldbach_partitions_of_the_even_integers_from_4_to_50_rev4b.svg.png" />
</p>

##### ※ Goldbach's conjecture Source Code
```C++
void goldbach(int number) {

	for (int ii = 0; ii < length; ii++) {
		int var = number - prime[ii];
			if (!check[var] && number == var + prime[ii]) {
				printf("%d = %d + %d\n", number, prime[ii], var);
				return;
			}
	}

	printf("Goldbach's conjecture is wrong.\n");
}
```

## ★ 무차별 대입 공격 (Brute force attack)

* 무차별 대입 공격(영어: brute force attack)은 특정한 암호를 풀기 위해 가능한 모든 값을 대입하는 것을 의미한다. 대부분의 암호화 방식은 이론적으로 무차별 대입 공격에 대해 안전하지 못하며, 충분한 시간이 존재한다면 암호화된 정보를 해독할 수 있다. 하지만 대부분의 경우 모든 계산을 마치려면 실용적이지 못한 비용이나 시간을 소요하게 되어, 공격을 방지하게 한다. 암호의 '취약점'이라는 의미에는 무차별 대입 공격보다 더 빠른 공격 방법이 존재한다는 것을 의미한다.

## ★ REFERENCE

:airplane: [Programmers - ㈜ 그렙](https://www.welcomekakao.com/learn/challenges)

:airplane: [Beakjoon Online Judge - ㈜ STARTLINK](https://www.acmicpc.net/)

:airplane: [에라토스테네스의 체 - 위키백과](https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4)

:airplane: [최대공약수 - 위키백과](https://ko.wikipedia.org/wiki/%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98)

:airplane: [골드바흐의 추측 (Goldbach's conjecture) - 위키백과](https://ko.wikipedia.org/wiki/%EA%B3%A8%EB%93%9C%EB%B0%94%ED%9D%90%EC%9D%98_%EC%B6%94%EC%B8%A1)

:airplane: [무차별 대입 공격(Brute force attack) - 위키백과](https://ko.wikipedia.org/wiki/%EB%AC%B4%EC%B0%A8%EB%B3%84_%EB%8C%80%EC%9E%85_%EA%B3%B5%EA%B2%A9)
