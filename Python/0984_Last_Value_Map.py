class LastValueMap:
    def __init__(self):
        self.stack = []
        self.lasts = {}

    def set(self, key, value):
        self.lasts[key] = value
        self.stack.append(key)

    def remove(self, key):
        if key in self.lasts:
            del self.lasts[key]

    def getLast(self):
        while self.stack[-1] not in self.lasts:
            self.stack.pop()
        return self.lasts[self.stack[-1]]
