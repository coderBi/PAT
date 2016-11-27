import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, maxCount = 0, key = 0, n = sc.nextInt();
		int arr[] = new int[n];
		HashMap<Integer, Integer> hmp = new HashMap<Integer, Integer>();

		for (i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}

		for (i = 0; i < n; i++) {
			if (hmp.get(arr[i]) == null) {
				hmp.put(arr[i], 1);
			} else {
				hmp.put(arr[i], hmp.get(arr[i]) + 1);
			}
		}
		
		Set<Map.Entry<Integer, Integer>> st = hmp.entrySet();
		
		Iterator<Map.Entry<Integer, Integer>> it = st.iterator();
		
		while(it.hasNext()){
			Map.Entry<Integer, Integer> p = it.next();
			if(p.getValue() > maxCount){
				maxCount = p.getValue();
				key = p.getKey();
			}
		}
		System.out.print(key + " " + maxCount);
	}
}