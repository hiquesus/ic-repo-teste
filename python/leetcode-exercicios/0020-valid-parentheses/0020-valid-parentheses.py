class Solution:
    def isValid(self, s: str) -> bool:
        pilha = []
        tipos = {")": "(", "]": "[", "}": "{"}
        
        for char in s:
            if char in tipos:
                if pilha and pilha[-1] == tipos[char]:
                    pilha.pop()
                else:
                    return False
            else:
                pilha.append(char)
        return True if not pilha else False