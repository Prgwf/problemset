#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int f[N], ch[N][2], key[N], cnt[N], size[N], sz, root;

void clear(int x) {
  ch[x][0] = ch[x][1] = f[x] = cnt[x] = key[x] = size[x] = 0;
}

int get(int x) {
  return ch[f[x]][1] == x;  
}

void update(int x) {
  if (not x) return;

  size[x] = cnt[x];
  if (ch[x][0]) size[x] += size[ch[x][0]];
  if (ch[x][1]) size[x] += size[ch[x][1]];
}

void rotate(int x) {
  int old = f[x], oldf = f[old], which = get(x);
  ch[old][which] = ch[x][which ^ 1];  f[ch[old][which]] = old;
  ch[x][which ^ 1] = old; f[old] = x;
  f[oldf] = x;
  if (oldf) ch[oldf][ch[oldf][1] == old] = x;
  update(old); update(x);
}

void splay(int x) {
  for (int fa; (fa = f[x]); rotate(x)) {
    if (f[fa]) rotate((get(x) == get(fa) ? fa : x));
  }
  root = x;
}


void insert(int v) {
  if (not root) {
    sz++; ch[sz][0] = ch[sz][1] = f[sz] = 0;
    key[sz] = v; cnt[sz] = 1; size[sz] = 1; 
    root = sz;
    return;
  }

  int pt = root, fa = 0;
  while (true) {
    if (key[pt] == v) {
      cnt[pt]++;
      update(pt); update(fa);
      splay(pt);
      break;
    }
    fa = pt;
    pt = ch[pt][key[pt] < v];
    if (not pt) {
      sz++;
      ch[sz][0] = ch[sz][1] = 0;
      key[sz] = v; size[sz] = 1;
      cnt[sz] = 1; f[sz] = fa; ch[fa][key[fa] < v] = sz;
      update(fa); 
      splay(sz);
      break;  
    }
  }
}

int find_by_value(int v) {
  int ans = 0, pt = root;
  while (true) {
    if (v < key[pt]) {
      pt = ch[pt][0];
    } else {
      ans += (ch[pt][0] ? size[ch[pt][0]] : 0);
      if (v == key[pt]) {
        splay(pt);
        return ans + 1;
      }
      ans += cnt[pt];
      pt = ch[pt][1];
    }
  }
}

int find_by_order(int x) {
  int pt = root;
  while (true) { 
    if (ch[pt][0] and x <= size[ch[pt][0]]) {
      pt = ch[pt][0];
    } else {
      int tmp = (ch[pt][0] ? size[ch[pt][0]] : 0) + cnt[pt];
      if (x <= tmp) {
        return key[pt];
      }
      x -= tmp;
      pt = ch[pt][1];
    }
  }
}

int pre() {
  int pt = ch[root][0];
  while (ch[pt][1]) pt = ch[pt][1];
  return pt;
}

int nxt() {
  int pt = ch[root][1];
  while (ch[pt][0]) pt = ch[pt][0];
  return pt;
}

void remove(int x) {
  find_by_value(x);
  if (cnt[root] > 1) {
    cnt[root]--;
    return;
  }


  if (not ch[root][0] and not ch[root][1]) {
    clear(root); root = 0; 
    return;
  }
  
  
  if (not ch[root][0]) {
    int oldrt = root;
    root = ch[root][1]; f[root] = 0;
    clear(oldrt);
    return;
  } else if (not ch[root][1]) {
    int oldrt = root;
    root = ch[root][0]; f[root] = 0;
    clear(oldrt);
    return;    
  }

  int leftbig = pre();
  int oldrt = root;
  splay(leftbig);
  f[ch[oldrt][1]] = root; ch[root][1] = ch[oldrt][1];
  clear(oldrt);
  update(root);
  return;
}

int main() {
  
}