int rangeBitwiseAnd(int m, int n) {
        int i;
        for(i=0; m!=n; m>>=1,n>>=1)
                i++;
        return m<<i;
}
