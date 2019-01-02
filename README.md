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

## ★ REFERENCE

:airplane: [Programmers - ㈜ 그렙](https://www.welcomekakao.com/learn/challenges)

:airplane: [Beakjoon Online Judge - ㈜ STARTLINK](https://www.acmicpc.net/)

:airplane: [에라토스테네스의 체 - 위키백과](https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4)

:airplane: [최대공약수 - ](https://ko.wikipedia.org/wiki/%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98)
