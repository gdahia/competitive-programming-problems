#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))
#define sqr(a) (a)*(a)

using namespace std;

struct Vector {
    long double x, y;

    long double sqnorm() {
        return sqr(x) + sqr(y);
    }
};

struct Point {
    long double x, y;

    Vector operator - (const Point & rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
};

struct Line {
    Vector d;
    Point p;
};

long double cross(const Vector & v, const Vector & r) {
    return v.x*r.y - v.y*r.x;
}

long double dot(const Vector & v, const Vector & r) {
    return v.x*r.x + v.y*r.y;
}

long double segdistance(const Point & v, const Point & w, const Point & p) {
    Vector vw = w-v, pv = p-v, pw = p-w;
    long double t = dot(pv, vw)/vw.sqnorm();
    if (t >= -1e-6 && t - 1 <= 1e-6) {
        long double c = cross(pw, vw);
        return sqr(c)/vw.sqnorm();
    }
    return pw.sqnorm();
}

int main() {
	int n;
    long double l, r;
    cout << fixed << setprecision(18);
    cin >> n;
    Point v[n + 1], o;
    cin >> o.x >> o.y >> v[0].x >> v[0].y;
    r = l = (v[0] - o).sqnorm();
    v[n] = v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        long double t = (v[i] - o).sqnorm();
        l = min(t, l);
        r = max(t, r);
    }
    for (int i = 1; i <= n; i++) {
        long double d = segdistance(v[i], v[i - 1], o);
        r = max(r, d);
        l = min(l, d);
    }
    long double ans = acos(-1)*(r - l);
    cout << ans << endl;
	return 0;
}