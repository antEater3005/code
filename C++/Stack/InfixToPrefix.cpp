#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int precedence(char c)

{

	if (c == '^')

		return 3;

	if (c == '*' || c == '/')

		return 2;

	if (c == '+' || c == '-')

		return 1;

	return -1;
}

string infixToprefix(string s)

{

	stack<char> st;

	string res;

	for (int i = s.length() - 1; i >= 0; i--)

	{

		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')

		{

			res = s[i] + res;
		}

		else if (s[i] == ')')

		{

			st.push(s[i]);
		}

		else if (s[i] == '(')

		{

			while ((!st.empty()) && st.top() != ')')

			{

				res = st.top() + res;

				st.pop();
			}

			if (!st.empty())

				st.pop();
		}

		else

		{

			while ((!st.empty()) && (precedence(s[i]) < precedence(st.top())))

			{

				res = st.top() + res;

				st.pop();
			}

			st.push(s[i]);
		}
	}

	while (!st.empty())

	{

		res = st.top() + res;

		st.pop();
	}

	return res;
}

int main()

{

	string s = "(a-b/c)*(a/k-l)";

	cout << infixToprefix(s);
}