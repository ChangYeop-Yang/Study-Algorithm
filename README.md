# ■ Study-Algorithm <kbd>[Kyungpook National University](http://www.knu.ac.kr/wbbs/)</kbd>
* 해당 Repository에 있는 소스코드들에 대한 문제에 대한 저작권은 알고리즘 문제 사이트에 귀속되어 있습니다.

<p align="center">
  <img src="https://user-images.githubusercontent.com/20036523/50101184-818d8a00-0265-11e9-9d75-ebb9fa3d0740.png" width="250" height="250" />
</p>

## ★ Factorial (계승)

* 수학에서, 자연수의 계승(階乘, 문화어: 차례곱, 영어: factorial 팩토리얼[*])은 그 수보다 작거나 같은 모든 양의 정수의 곱이다. n이 하나의 자연수일 때, 1에서 n까지의 모든 자연수의 곱을 n에 상대하여 이르는 말이다. 기호는 !을 쓰며 팩토리얼이라고 읽는다. 팩토리얼을 줄여서 팩이라고 읽기도 한다.

```C++
#define LONG long long

LONG factorial(int index) {

	if (index <= 1) { return 1; }

	// Memorization
	if (answer[index] > 1) { return answer[index]; }

	answer[index] = index * factorial(index - 1);

	return answer[index];
}
```

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

## ★ 회문수 (回文數, Palindromic number)

* 대칭수(對稱數) 또는 회문수(回文數)는 순서대로 읽은 수와 거꾸로 읽은 수가 일치하는 수를 말한다. 예를 들면 34543은 대칭수이고, 34567은 대칭수가 아니다. 컴퓨터 학자 그루엔버거(F.Gruenberger)는 1984년에 미국의 잡지〈사이언티픽 아메리칸〉에 싣게 된 ‘컴퓨터 레크리에이션’이라는 칼럼에서 이와 같은 흥미로운 알고리즘을 제시해서 많은 사람의 이목을 끌었다. 2002는 2와 2, 0과 0의 위치를 바꿔도 대칭수이다.

```C++
#define STRING_PAIR pair<string, string>

// Under 100,000,000 List
vector<int> palindrome = {2,3,5,7,11,101,131,151,181,191,313,353,373,383,727,757,787,797,919,929,10301,10501,10601,11311,11411,12421,12721,12821,13331,13831,13931,14341,14741,15451,15551,16061,16361,16561,16661,17471,17971,18181,18481,19391,19891,19991,30103,30203,30403,30703,30803,31013,31513,32323,32423,33533,34543,34843,35053,35153,35353,35753,36263,36563,37273,37573,38083,38183,38783,39293,70207,70507,70607,71317,71917,72227,72727,73037,73237,73637,74047,74747,75557,76367,76667,77377,77477,77977,78487,78787,78887,79397,79697,79997,90709,91019,93139,93239,93739,94049,94349,94649,94849,94949,95959,96269,96469,96769,97379,97579,97879,98389,98689,1003001,1008001,1022201,1028201,1035301,1043401,1055501,1062601,1065601,1074701,1082801,1085801,1092901,1093901,1114111,1117111,1120211,1123211,1126211,1129211,1134311,1145411,1150511,1153511,1160611,1163611,1175711,1177711,1178711,1180811,1183811,1186811,1190911,1193911,1196911,1201021,1208021,1212121,1215121,1218121,1221221,1235321,1242421,1243421,1245421,1250521,1253521,1257521,1262621,1268621,1273721,1276721,1278721,1280821,1281821,1286821,1287821,1300031,1303031,1311131,1317131,1327231,1328231,1333331,1335331,1338331,1343431,1360631,1362631,1363631,1371731,1374731,1390931,1407041,1409041,1411141,1412141,1422241,1437341,1444441,1447441,1452541,1456541,1461641,1463641,1464641,1469641,1486841,1489841,1490941,1496941,1508051,1513151,1520251,1532351,1535351,1542451,1548451,1550551,1551551,1556551,1557551,1565651,1572751,1579751,1580851,1583851,1589851,1594951,1597951,1598951,1600061,1609061,1611161,1616161,1628261,1630361,1633361,1640461,1643461,1646461,1654561,1657561,1658561,1660661,1670761,1684861,1685861,1688861,1695961,1703071,1707071,1712171,1714171,1730371,1734371,1737371,1748471,1755571,1761671,1764671,1777771,1793971,1802081,1805081,1820281,1823281,1824281,1826281,1829281,1831381,1832381,1842481,1851581,1853581,1856581,1865681,1876781,1878781,1879781,1880881,1881881,1883881,1884881,1895981,1903091,1908091,1909091,1917191,1924291,1930391,1936391,1941491,1951591,1952591,1957591,1958591,1963691,1968691,1969691,1970791,1976791,1981891,1982891,1984891,1987891,1988891,1993991,1995991,1998991,3001003,3002003,3007003,3016103,3026203,3064603,3065603,3072703,3073703,3075703,3083803,3089803,3091903,3095903,3103013,3106013,3127213,3135313,3140413,3155513,3158513,3160613,3166613,3181813,3187813,3193913,3196913,3198913,3211123,3212123,3218123,3222223,3223223,3228223,3233323,3236323,3241423,3245423,3252523,3256523,3258523,3260623,3267623,3272723,3283823,3285823,3286823,3288823,3291923,3293923,3304033,3305033,3307033,3310133,3315133,3319133,3321233,3329233,3331333,3337333,3343433,3353533,3362633,3364633,3365633,3368633,3380833,3391933,3392933,3400043,3411143,3417143,3424243,3425243,3427243,3439343,3441443,3443443,3444443,3447443,3449443,3452543,3460643,3466643,3470743,3479743,3485843,3487843,3503053,3515153,3517153,3528253,3541453,3553553,3558553,3563653,3569653,3586853,3589853,3590953,3591953,3594953,3601063,3607063,3618163,3621263,3627263,3635363,3643463,3646463,3670763,3673763,3680863,3689863,3698963,3708073,3709073,3716173,3717173,3721273,3722273,3728273,3732373,3743473,3746473,3762673,3763673,3765673,3768673,3769673,3773773,3774773,3781873,3784873,3792973,3793973,3799973,3804083,3806083,3812183,3814183,3826283,3829283,3836383,3842483,3853583,3858583,3863683,3864683,3867683,3869683,3871783,3878783,3893983,3899983,3913193,3916193,3918193,3924293,3927293,3931393,3938393,3942493,3946493,3948493,3964693,3970793,3983893,3991993,3994993,3997993,3998993,7014107,7035307,7036307,7041407,7046407,7057507,7065607,7069607,7073707,7079707,7082807,7084807,7087807,7093907,7096907,7100017,7114117,7115117,7118117,7129217,7134317,7136317,7141417,7145417,7155517,7156517,7158517,7159517,7177717,7190917,7194917,7215127,7226227,7246427,7249427,7250527,7256527,7257527,7261627,7267627,7276727,7278727,7291927,7300037,7302037,7310137,7314137,7324237,7327237,7347437,7352537,7354537,7362637,7365637,7381837,7388837,7392937,7401047,7403047,7409047,7415147,7434347,7436347,7439347,7452547,7461647,7466647,7472747,7475747,7485847,7486847,7489847,7493947,7507057,7508057,7518157,7519157,7521257,7527257,7540457,7562657,7564657,7576757,7586857,7592957,7594957,7600067,7611167,7619167,7622267,7630367,7632367,7644467,7654567,7662667,7665667,7666667,7668667,7669667,7674767,7681867,7690967,7693967,7696967,7715177,7718177,7722277,7729277,7733377,7742477,7747477,7750577,7758577,7764677,7772777,7774777,7778777,7782877,7783877,7791977,7794977,7807087,7819187,7820287,7821287,7831387,7832387,7838387,7843487,7850587,7856587,7865687,7867687,7868687,7873787,7884887,7891987,7897987,7913197,7916197,7930397,7933397,7935397,7938397,7941497,7943497,7949497,7957597,7958597,7960697,7977797,7984897,7985897,7987897,7996997,9002009,9015109,9024209,9037309,9042409,9043409,9045409,9046409,9049409,9067609,9073709,9076709,9078709,9091909,9095909,9103019,9109019,9110119,9127219,9128219,9136319,9149419,9169619,9173719,9174719,9179719,9185819,9196919,9199919,9200029,9209029,9212129,9217129,9222229,9223229,9230329,9231329,9255529,9269629,9271729,9277729,9280829,9286829,9289829,9318139,9320239,9324239,9329239,9332339,9338339,9351539,9357539,9375739,9384839,9397939,9400049,9414149,9419149,9433349,9439349,9440449,9446449,9451549,9470749,9477749,9492949,9493949,9495949,9504059,9514159,9526259,9529259,9547459,9556559,9558559,9561659,9577759,9583859,9585859,9586859,9601069,9602069,9604069,9610169,9620269,9624269,9626269,9632369,9634369,9645469,9650569,9657569,9670769,9686869,9700079,9709079,9711179,9714179,9724279,9727279,9732379,9733379,9743479,9749479,9752579,9754579,9758579,9762679,9770779,9776779,9779779,9781879,9782879,9787879,9788879,9795979,9801089,9807089,9809089,9817189,9818189,9820289,9822289,9836389,9837389,9845489,9852589,9871789,9888889,9889889,9896989,9902099,9907099,9908099,9916199,9918199,9919199,9921299,9923299,9926299,9927299,9931399,9932399,9935399,9938399,9957599,9965699,9978799,9980899,9981899,9989899};

void setPalindrome(const int prime) {

	STRING_PAIR comp = make_pair(string(), string());
	comp.first = comp.second = to_string(prime);

	reverse(comp.second.begin(), comp.second.end());

	if (comp.first == comp.second) { palindrome.push_back(prime); }
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

## ★ Mask

* In computer science, a mask is data that is used for bitwise operations, particularly in a bit field. Using a mask, multiple bits in a byte, nibble, word etc. can be set either on, off or inverted from on to off (or vice versa) in a single bitwise operation.

##### ※ Mask Source Code

```C++
bool mask(int number, const int target) {
	int bit = (1 << target);
	return (number & bit) == bit; // Duplicate True
	
	// ※ INSERT -> number |= bit
	// ※ DELETE and Toggle -> number ^= bit
}
```

## ★ 순열 (Permutation)

* 서로 다른 nn개의 원소에서 rr개를 중복없이 골라 순서에 상관있게 나열하는 것을 nn개에서 rr개를 택하는 순열이라고 한다.

##### ※ Next Permutation Source Code

```C++
#define SWAP(X, Y, Z) Z=X; X=Y; Y=Z;

bool nextPermutation(vector<int> arr, int n) {

	int temp = 0;

	/* 001. A[i-1] < A[i]를 만족하는 가장 큰 i를 찾는다. */
	int ii = n - 1;
	while (ii > 0 && arr[ii] <= arr[ii - 1]) { ii--; }

	/* Last Permutation */
	if (ii <= 0) { return false; }

	/* 002. A[i-1] < A[j]를 만족하는 가장 큰 j를 찾는다. (j>=i) */
	int jj = n - 1;
	while (jj >= ii && arr[jj] <= arr[ii - 1]) { jj--; }
	
	/* 003. A[i-1]과 A[j]를 SWAP 한다. */
	SWAP(arr[ii - 1], arr[jj], temp);

	/* A[ii]부터 순열을 뒤집는다. */
	for (int tt = n - 1; ii < tt; tt--, ii++) {
		SWAP(arr[ii], arr[tt], temp);
	}
	
	return true;
}

```

##### ※ Privious Permutation Source Code

```C++
#define SWAP(X, Y, Z) Z=X; X=Y; Y=Z;

bool priviousPermutation(vector<int> arr, int n) {

	int temp = 0;

	int ii = n - 1;
	while (ii > 0 && arr[ii] >= arr[ii - 1]) { ii--; }

	if (ii <= 0) { return false; }

	int jj = n - 1;
	while (jj >= ii && arr[jj] >= arr[ii - 1]) { jj--; }
	SWAP(arr[ii - 1], arr[jj], temp);

	for (int tt = n - 1; ii < tt; tt--, ii++) {
		SWAP(arr[ii], arr[tt], temp);
	}

	return true;
}
```

## ★ Traveling Salesperson Problem

* 외판원 문제(外販員問題, 영어: traveling salesperson problem) 또는 순회 외판원 문제는 조합 최적화 문제의 일종이다. 줄여서 TSP라고도 쓴다. 이 문제는 NP-난해에 속하며, 흔히 계산 복잡도 이론에서 해를 구하기 어려운 문제의 대표적인 예로 많이 다룬다.

* 여러 도시들이 있고 한 도시에서 다른 도시로 이동하는 비용이 모두 주어졌을 때, 모든 도시들을 단 한 번만 방문하고 원래 시작점으로 돌아오는 최소 비용의 이동 순서를 구하는 것이다.

##### [※ Traveling Salesperson Problem Source Code (Brute force attack)](https://www.acmicpc.net/problem/10971)

```C++
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int generation() {
	unsigned static int number = 0;
	return number++;
}

int main(void)
{
	unsigned int number = 0;
	cin >> number;

	vector<vector<int> > city = vector<vector<int> >(number);
	for (unsigned int ii = 0; ii < number; ii++) {
		city[ii] = vector<int>(number);
		for (unsigned int jj = 0; jj < number; jj++) {
			cin >> city[ii][jj];
		}
	}

	vector<int> visit = vector<int>(number);
	generate(visit.begin(), visit.end(), generation);

	register int minVal = INT_MAX;

	do {
		register pair<bool, long> value = make_pair(false, 0);
		
		for (unsigned int ii = 0; ii < number - 1; ii++) {
			
			register int weight = city[visit[ii]][visit[ii + 1]];
			if (weight == 0) { value.first = true; continue; }

			value.second += weight;
		}

		/* 도착점에서 다시 출발점으로 돌아오는 경우 (city[ visit[number - 1]][visit[0] ]) */
		register int weigth = city[visit[number - 1]][visit[0]];
		if (value.first || weigth == 0) { continue; }

		if (minVal > weigth + value.second) { minVal = weigth + value.second; }

	} while ( next_permutation(visit.begin(), visit.end()) );

	cout << minVal << endl;

	return 0;
}
```

## ★ 탐욕 알고리즘 (Greedy Algorithm)

* **탐욕 알고리즘은 최적해를 구하는 데에 사용되는 근사적인 방법으로, 여러 경우 중 하나를 결정해야 할 때마다 그 순간에 최적이라고 생각되는 것을 선택해 나가는 방식으로 진행하여 최종적인 해답에 도달한다. 순간마다 하는 선택은 그 순간에 대해 지역적으로는 최적이지만, 그 선택들을 계속 수집하여 최종적(전역적)인 해답을 만들었다고 해서, 그것이 최적이라는 보장은 없다.** </br></br>탐욕 알고리즘이 잘 작동하는 문제는 대부분 탐욕스런 선택 조건(greedy choice property)과 최적 부분 구조 조건(optimal substructure)이라는 두 가지 조건이 만족된다. 탐욕스런 선택 조건은 앞의 선택이 이후의 선택에 영향을 주지 않는다는 것이며, 최적 부분 구조 조건은 문제에 대한 최적해가 부분문제에 대해서도 역시 최적해라는 것이다. </br></br>이러한 조건이 성립하지 않는 경우에는 탐욕 알고리즘은 최적해를 구하지 못한다. 하지만, 이러한 경우에도 탐욕 알고리즘은 근사 알고리즘으로 사용이 가능할 수 있으며, 대부분의 경우 계산 속도가 빠르기 때문에 실용적으로 사용할 수 있다. 이 경우 역시 어느 정도까지 최적해에 가까운 해를 구할 수 있는지를 보장하려면 엄밀한 증명이 필요하다. 어떤 특별한 구조가 있는 문제에 대해서는 탐욕 알고리즘이 언제나 최적해를 찾아낼 수 있다.

##### [※ Greedy Algorithm Source Code - 거스름돈](https://www.acmicpc.net/problem/5585)

```C++
vector<int> coin = {500, 100, 50, 10, 5, 1};

	int index = 0;
	pair<int, int> answer = make_pair(0, 0);
	while (true) {

		// 거스름돈의 최적의 해를 구한 경우
		if (answer.second == cost) { cout << answer.first << endl; break; }

		// 구하고자 한는 값보다 동전의 값이 더 큰 경우는 버린다.
		if (cost < coin[index]) { index++; continue; }
		// 현재 구해 진 거스름돈에 다음 동전을 더하였을 때 구하고자 하는 값보다 더 큰 경우는 버린다.
		if (answer.second + coin[index] > cost) { index++; continue; }

		answer.first++;
		answer.second += coin[index];
	}
```

## ★ 회전변환행렬 (Rotation Matrix)

<p align="center">
	<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/3a/Matrix-font-linear-map001Rota.svg/300px-Matrix-font-linear-map001Rota.svg.png" />
</p>

* 선형 변환에서 회전변환행렬(Rotation matrix)은 임의의 행렬을 원점을 중심으로 회전시킨다. 회전변환행렬(Rotation matrix)은 선형 변환의 성질중 하나이며, 동시에 여러 회전변환행렬중 일부는 대칭변환행렬 즉 반사행렬(Reflection matrix)과 관련이 있다.

##### ※ [Sources By LeetCode (shichaotan)](https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image)

```C++
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
	
    reverse(matrix.begin(), matrix.end());
    /* 
	for (int ii = 0; ii <= length / 2; ii++) {
            for (int jj = 0; jj <= length; jj++) { SWAP(matrix[ii][jj], matrix[length - ii][jj], temp); }
        }
    */
	
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j) { swap(matrix[i][j], matrix[j][i]); }
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
```

## ★ REFERENCE

:airplane: [Programmers - ㈜ 그렙](https://www.welcomekakao.com/learn/challenges)

:airplane: [Beakjoon Online Judge - ㈜ STARTLINK](https://www.acmicpc.net/)

:airplane: [2018 SW 역량 테스트 준비 (기초) - Code.Plus](https://code.plus/)

:airplane: [Factorial (계승) - ](https://ko.wikipedia.org/wiki/%EA%B3%84%EC%8A%B9)

:airplane: [에라토스테네스의 체 - 위키백과](https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4)

:airplane: [최대공약수 - 위키백과](https://ko.wikipedia.org/wiki/%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98)

:airplane: [골드바흐의 추측 (Goldbach's conjecture) - 위키백과](https://ko.wikipedia.org/wiki/%EA%B3%A8%EB%93%9C%EB%B0%94%ED%9D%90%EC%9D%98_%EC%B6%94%EC%B8%A1)

:airplane: [무차별 대입 공격 (Brute force attack) - 위키백과](https://ko.wikipedia.org/wiki/%EB%AC%B4%EC%B0%A8%EB%B3%84_%EB%8C%80%EC%9E%85_%EA%B3%B5%EA%B2%A9)

:airplane: [순열 (Permutation) - 나무위키](https://namu.wiki/w/%EC%88%9C%EC%97%B4)
 
:airplane: [Mask (computing) - 위키백과](https://en.wikipedia.org/wiki/Mask_(computing))

:airplane: [탐욕 알고리즘 (Greedy Algorithm) - 위키백과](https://ko.wikipedia.org/wiki/%ED%83%90%EC%9A%95_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

:airplane: [회문수 (回文數, Palindromic number) - 위키백과](https://ko.wikipedia.org/wiki/%EB%8C%80%EC%B9%AD%EC%88%98)

:airplane: [회전변환행렬 (Rotation Matrix) - 위키백과](https://ko.wikipedia.org/wiki/%ED%9A%8C%EC%A0%84%EB%B3%80%ED%99%98%ED%96%89%EB%A0%AC)
