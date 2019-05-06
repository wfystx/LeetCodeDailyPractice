class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        to19 = 'One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve ' \
               'Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen'.split()
        tens = 'Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety'.split()
        
        def check(word):
            if word < 20:
                return to19[word-1:word]
            if word < 100:
                return [tens[word/10-2]] + check(word%10)
            if word < 1000:
                return [to19[word/100-1]]+ ['Hundred'] + check(word%100)
            for p,w in enumerate(('Thousand','Million','Billion'),1):
                if word < 1000**(p+1):
                    return check(word/(1000**p)) + [w] + check(word%1000**p)
        return ' '.join(check(num)) or 'Zero'