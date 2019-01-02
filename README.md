# ■ Study-Algorithm
* 해당 Repository에 있는 소스코드들에 대한 문제에 대한 저작권은 알고리즘 문제 사이트에 귀속되어 있습니다.

<p align="center">
  <img src="https://user-images.githubusercontent.com/20036523/50101184-818d8a00-0265-11e9-9d75-ebb9fa3d0740.png" width="250" height="250" />
</p>

## ★ Greatest common divisor (최대 공약수)

* 수론에서, 정수들의 공약수(公約數, 영어: common divisor)는 동시에 그들 모두의 약수인 정수다. 적어도 하나가 0이 아닌 정수들의 최대공약수(最大公約數, 문화어: 련속나눔셈; 영어: greatest common divisor, 약자 GCD)는 공약수 가운데 가장 큰 하나다. 다항식이나 환의 원소에 대해서도 정의할 수 있다.

##### ※ Greatest common divisor Source Code

## ★ Eratosthenes (에라토스테네스의 체)

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif" />
</p>

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

## ★ REFERENCE

:airplane: [Programmers - ㈜ 그렙](https://www.welcomekakao.com/learn/challenges)

:airplane: [Beakjoon Online Judge - ㈜ STARTLINK](https://www.acmicpc.net/)
