class TimeMap {

    private HashMap<String, ArrayList<Pair<Integer, String>>> mpp;

    public TimeMap() {
        this.mpp = new HashMap<String, ArrayList<Pair<Integer, String>>>();
    }
    
    public void set(String key, String value, int timestamp) {

        if(this.mpp.containsKey(key))
        {
            ArrayList<Pair<Integer, String>> old =  mpp.get(key);
            Pair<Integer, String> newPair = new Pair<Integer, String>(timestamp, value);
            old.add(newPair);
            mpp.put(key, old);
        }
        else 
        {
            ArrayList<Pair<Integer, String>> newList = new ArrayList<Pair<Integer, String>>();
            Pair<Integer, String> newPair = new Pair<Integer, String>(timestamp, value);
            newList.add(newPair);
            mpp.put(key, newList);
        }
        return;
        
    }
    
    public String get(String key, int timestamp) {
        
        if(!this.mpp.containsKey(key))return "";
        ArrayList<Pair<Integer, String>> list =  this.mpp.get(key);
        String ans = "";
        int i = 0, j = list.size()-1;

        while(i<=j)
        {
            int mid = i + (j-i)/2;
            Pair<Integer, String> pr = list.get(mid);
            if(pr.getKey() <= timestamp)
            {
                i = mid+1;
                ans = pr.getValue();
            }
            else j = mid-1;
        }

        return ans;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */