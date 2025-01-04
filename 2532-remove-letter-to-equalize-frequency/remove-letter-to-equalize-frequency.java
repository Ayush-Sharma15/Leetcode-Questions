class Solution {
    public boolean check(int i,String word,HashMap<Character,Integer> map){
        HashMap<Character,Integer> tmap=new HashMap<>(map);
        char c=word.charAt(i);
        int freq=tmap.get(c)-1;
        if (freq == 0) {
            tmap.remove(c);
        } else {
            tmap.put(c, freq);
        }
        int flag=-1;
        for(Map.Entry<Character,Integer> entry:tmap.entrySet()){
           int val=entry.getValue();
           if(flag==-1){
                flag=val;
           }else if(flag!=val){
            return false;
           }
        }
        return true;
    }
    public boolean equalFrequency(String word) {
        HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<word.length();i++){
            char ch=word.charAt(i);
            if(map.containsKey(ch)){
                map.put(ch,map.get(ch)+1);
            }else{
                map.put(ch,1);
            }
        }
        HashSet<Integer> set=new HashSet<>();
        for(int i=0;i<word.length();i++){
            if(check(i,word,map)){
                return true;
            }
        }
        return false;
    }
}