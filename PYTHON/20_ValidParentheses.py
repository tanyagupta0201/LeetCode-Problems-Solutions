class Solution:
   def isValid(self, s):
      size = len(s)
      pre = 0
      while pre != size:
        pre = size
        s = s.replace('()', '').replace('[]', '').replace('{}', '')    		    		
        size = len(s)

        return size == 0