#String 
#split('@')
#.replace('.','')

class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        s = set()
        for i in emails:
            local,domain = i.split('@')
            if '+' in local:
                local = local[:local.index('+')]
            s.add(local.replace('.','')+'@'+domain)
        return len(s)