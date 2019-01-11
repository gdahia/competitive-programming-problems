def solve(x):
  x *= 10**30

  l = 0
  r = x
  while l < r:
    m = l + (r - l + 1) / 2
    if m**3 <= x:
      l = m
    else:
      r = m - 1

  return l


def main():
  t = input()
  while t:
    a = [c for c in raw_input() if c != ' ']
    if a:
      x = int(''.join([c for c in a]))
      str_ans = str(solve(x))
      int_, dec = str_ans[:-10], str_ans[-10:]
      sum_ = sum([int(x) for x in str(int_ + dec)]) % 10
      print sum_, int_ + '.' + dec

      t -= 1


if __name__ == '__main__':
  main()
