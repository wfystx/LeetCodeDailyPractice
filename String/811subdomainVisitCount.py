class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        ans = collections.Counter()
        for i in cpdomains:
            time, domain = i.split()
            time = int(time)
            frag = domain.split('.')
            for j in range(len(frag)):
                ans['.'.join(frag[j:])] += time
        return ['{} {}'.format(c,dom) for dom,c in ans.items()]