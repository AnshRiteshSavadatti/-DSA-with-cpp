//  Reset in Range
// https://www.naukri.com/code360/problems/reset-in-range_972998?topList=jp-morgan-interview-questions&problemListRedirection=true&count=25&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav&page=2


#include <bits/stdc++.h> 
int resetAllBitsInRange(int n, int l, int r) 
{
	for(int i =r-1; i <= l-1; i++){
		int mask = (1 << i);
		mask = ~mask;

		n &= mask;
	}

	return n;

}