var compute = function(array,startIndex,endIndex){
	var middle =Math.floor((startIndex + endIndex)/2);
	console.log("Current start:" + startIndex);
	console.log("Current end:" + endIndex);
	console.log("Current middle:" + middle);
	console.log("=========================");
	if(startIndex == endIndex){
		if(startIndex == 0 && array.length > 1 && (array[0] < array[1]) ){
			console.log("Answer is value " + array[startIndex]);
			return 1;
		}
		else if(endIndex == array.length -1 && array.length > 1 && (array[endIndex-1] < array[endIndex]) ){
			console.log("Answer is value " + array[endIndex]);
			return 1;
		}
	}
	else if(startIndex > endIndex) return -1;	
	if(isAnswer(array,middle)){
		console.log("++++Answer is value " + array[middle]);
		return 1;
	}
	else{
		left_diff = array[startIndex] - array[middle];
		right_diff = array[middle] - array[endIndex];
		// console.log("left_diff:"+left_diff);
		// console.log("right_diff:"+ right_diff);
		// console.log("array[middle+1]:"+array[middle+1]);
		if(left_diff < 0){
			return compute(array,startIndex,middle-1);
		}else if(right_diff < 0){
			return compute(array,middle+1,endIndex);
		}else{
			if(compute(array,startIndex,middle-1) == 1) return 1;
			if(compute(array,middle+1,endIndex) == 1) return 1;
		}
		return -1;
	}
}
var isAnswer = function(array,middle){
	// console.log("array[middle-1]:"+array[middle-1]);
	// console.log("array[middle]:"+array[middle]);
	// console.log("array[middle+1]:"+array[middle+1]);
	if((array[middle-1] < array[middle]) &&((array[middle]) < array[middle+1])){
		return true;
	}
	return false;
}

var array = [5,4,3,1,5,6,7,7];
//var array = [7,7,7,1,7,7,7,7];
//var array = [7,7];
if(compute(array,0,array.length-1) == -1){
	console.log("No Answer");
}