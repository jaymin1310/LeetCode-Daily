class Solution {
    class Pair{
        int first;
        int second;
        Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    }
    public int[][] updateMatrix(int[][] mat) {
        int m=mat.length;
        int n=mat[0].length;
        int[][] ans=new int[m][n];
        Queue<Pair>qu=new LinkedList<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    qu.add(new Pair(i,j));
                }else{
                    ans[i][j]=-1;
                }
            }
        }
        while (!qu.isEmpty()) {
            Pair q=qu.poll();
            int i=q.first;
            int j=q.second;
            int curr=ans[i][j];
            if(i+1<m && ans[i+1][j]==-1){
                ans[i+1][j]=curr+1;
                qu.add(new Pair(i+1,j));
            }
            if(i-1>=0 && ans[i-1][j]==-1){
                ans[i-1][j]=curr+1;
                qu.add(new Pair(i-1,j));
            }
            if(j+1<n && ans[i][j+1]==-1){
                ans[i][j+1]=curr+1;
                qu.add(new Pair(i,j+1));
            }
            if(j-1>=0 && ans[i][j-1]==-1){
                ans[i][j-1]=curr+1;
                qu.add(new Pair(i,j-1));
            }
        }
        return ans;
    }
}