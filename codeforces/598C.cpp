#include <bits/stdc++.h>

using namespace std;

struct Vector {
	long long x, y, quadrant, sqnorm;
	int i, ans1, ans2;

	void find_quadrant() {
		if (x >= 0) {
			if (y >= 0) 
				quadrant = 1;
			else
				quadrant =  4;
		}
		else {
			if (y >= 0) 
				quadrant =  2;
			else
				quadrant =  3;
		}
	}
};

long long dot(const Vector & a, const Vector & b) {
	return(a.x*b.x + a.y*b.y);
}

long long cross(const Vector & a, const Vector & b) {
	return (a.x*b.y - a.y*b.x);
}

bool cmp(const Vector & a, const Vector & b) {
	return (a.quadrant < b.quadrant || (a.quadrant == b.quadrant && cross(a, b) > 0));
}

long long sq(long long a) {
	return (a*a);
}

/*void update_ans(int a, int b, pair <int, int> & ans, Vector * v) {
	if (abs(v[a].quadrant - v[b].quadrant) + 1 <= abs(v[ans.first].quadrant - v[ans.second].quadrant) || (abs(v[a].quadrant - v[b].quadrant) <= abs(v[ans.first].quadrant - v[ans.second].quadrant) && v[ans.first].sqnorm * v[ans.second].sqnorm * sq( cross(v[a], v[b]) ) < v[a].sqnorm * v[b].sqnorm * sq( cross(v[ans.first], v[ans.second]) ))) {
		ans.first = b;
		ans.second = a;
	}
}*/

int main() {
	int n;
	scanf("%d", &n);
	Vector v[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
		v[i].i = i + 1;
		v[i].sqnorm = v[i].x*v[i].x + v[i].y*v[i].y;
		v[i].find_quadrant();
	}
	sort(v, v+n, cmp);
	/*pair <int, int> ans;
	ans.first = 0;
	ans.second = 1;
	for (int i = 2; i < n; i++) {
		update_ans(i, i - 1, ans, v);
	}
	update_ans(0, n - 1, ans, v);*/
	Vector resp[n];
	for (int i = 1; i < n; i++) {
		resp[i].x = dot(v[i], v[i - 1]);
		resp[i].y = abs(cross(v[i], v[i - 1]));
		resp[i].ans1 = v[i].i;
		resp[i].ans2 = v[i - 1].i;
		resp[i].find_quadrant();
	}
	resp[0].x = dot(v[0], v[n - 1]);
	resp[0].y = abs(cross(v[0], v[n - 1]));
	resp[0].ans1 = v[0].i;
	resp[0].ans2 = v[n - 1].i;
	resp[0].find_quadrant();
	sort(resp, resp + n, cmp);
	printf("%d %d\n", resp[0].ans1, resp[0].ans2);
	return 0;
}