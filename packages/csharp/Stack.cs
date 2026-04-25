namespace csharp_packages;

public class MyStack<T> {
    private readonly System.Collections.Generic.List<T> _items = new();
    public void Push(T item) => _items.Add(item);
    public T Pop() {
        if (_items.Count == 0) throw new System.InvalidOperationException("Stack is empty");
        var item = _items[^1];
        _items.RemoveAt(_items.Count - 1);
        return item;
    }
    public bool IsEmpty => _items.Count == 0;
}

public static class StackUtilities {
    public static bool IsValidParentheses(string s) {
        var stack = new MyStack<char>();
        foreach (char c in s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.Push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.IsEmpty) return false;
                char top = stack.Pop();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        return stack.IsEmpty;
    }
}