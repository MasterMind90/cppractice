import java.util.*;
public class Main {
    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);
        String str1 = scan.next();
        String str2 = scan.next();
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        boolean flag=false; 
        for(int i=0;i<str1.length();i++){
            if ( str1.charAt(i) == str2.charAt(i)){
                continue;
            }
            else if (str1.charAt(i) < str2.charAt(i)) {
                System.out.println(-1);
                flag=true;
                break;
            }
            else {
                System.out.println(1);
                flag=true;
                break;
            }
        }
        if (flag==false)System.out.println(0);
    }
}
