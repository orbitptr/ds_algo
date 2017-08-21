
import java.util.Comparator;
import java.util.PriorityQueue;
// BinaryHeap class

/**
* Implements a binary heap.
* Note that all "matching" is based on a provided Comparator
* @author Mark Allen Weiss
* @author Luke McDowell
* @author Albert J. Wong
* Modified by Luke McDowell, July 2003
* Modified by Albert J Wong, Octoboer 2003
*   - Fixed some style issues . For instance, extracted a
*     corresponding percolate up function since there was a
*     percolate down function.
*   - BTW, Weiss has a memory leak in this code (stupid Weiss -- I hate
*     his code. His explanations are great, but code...ugh). I left it in
*     and gave it as an exercise to the students to fix it. (Hi
*     guys!  Don't you love me? :P)
*   - Removed BuildHeap.  It was private, but, wasn't used
*     anywhere in this class.  There's no way to access the underlying
*     array to end up with an unordered array anyway, so it really
*     has no use.  Did I mention Weiss's code sucks?
*/
public class BinaryHeap implements PriorityQueue {
	/**
	 * Construct a binary heap with a default capacity.
	 *
	 * @param c		An instance of the comparator to use for
	 * 			ordering the heap
	 */
	public BinaryHeap(Comparator c) {
		this(c, DEFAULT_CAPACITY );
	}



	/**
	 * Construct a binary heap with the given capacity.
	 *
	 * @param c		An instance of the comparator to use for
	 * 			ordering the heap
	 * @param capacity	The capacity of the binary heap.
	 */
	public BinaryHeap(Comparator c, int capacity ) {
		comparator  = c;
		size = 0;
		data = new Object[ capacity + 1 ];
	}



	/**
	 * Insert an object into the priority queue, maintaining heap order.
	 * Duplicates are allowed.
	 *
	 * @param x 		the object to insert.
	 * @exception OverflowException		Thrown if the heap is full.
	 */
	public void insert( Object x ) {
		if( isFull() ) {
			throw new OverflowException();
		}

		data[ size + 1 ] = x;

		// Percolate up
		percolateUp(size + 1); 


		// Now that we're sure we managed to add this element
		++size;
	}



	/**
	 * Find the smallest item in the priority queue.
	 *
	 * @return 	the smallest item
	 * @exception EmptyHeapException	Thrown if find is done on an
	 * 					empty heap.
	 */
	public Object findMin() {
		if( isEmpty() ) {
			throw new EmptyHeapException();
		}

		return data[ 1 ];
	}



	/**
	 * Remove the smallest item from the priority queue.
	 *
	 * @return the smallest item
	 * @exception EmptyHeapException  	Thrown if find is done on an
	 * 					empty heap.
	 */
	public Object deleteMin() {
		if( isEmpty() ) {
			throw new EmptyHeapException();
		}

		// We could use findMin here to "reuse more code"
		// but, it's kind of silly since findMin returns
		// data[1], and we make that assumption for the
		// rest of the code anyway, so it's more clear
		// to show the exact manipulation rather than
		// call a function and then make assumptions about
		// its implementation.
		Object minItem = data[1];

		// Move the last child to the top of the tree preserving
		// the complete nature of the tree.
		data[ 1 ] = data[ size ];

		// Percolate that object down to restore heap order
		// property.
		percolateDown( 1 );

		// Now that we're sure we've got everything right, we
		// decrement the size.
		--size;

		return minItem;
	}



	/**
	 * Test if the priority queue is logically empty.
	 * @return true if empty, false otherwise.
	 */
	public boolean isEmpty() {
		return size == 0;
	}



	/**
	 * Test if the priority queue is logically full.
	 * @return true if full, false otherwise.
	 */
	public boolean isFull() {
		return size == data.length - 1;
	}



	/**
	 * Make the priority queue logically empty.
	 */
	public void makeEmpty() {
		size = 0;
	}
	


	/**
	 * Method to percolate up from a given node in the heap.
	 *
	 * @param startNode	the index of the node at which the percolate begins.
	 */
	private void percolateUp( int startNode ) {
		int hole;

		Object tmp = data[startNode];

		for( hole = startNode; 
			hole > 1 && comparator.compare(tmp, data[ hole / 2 ] ) < 0; 
			hole /= 2 )
		{
			data[ hole ] = data[ hole / 2 ];
		}

		data[ hole ] = tmp;
	}



	/**
	 * Method to percolate down from a given node in the heap.
	 *
	 * @param startNode	the index of the node at which the percolate begins.
	 */
	private void percolateDown( int startNode ) {

		/* I changed the variable to "startNode" because using an
		 * argument as a regular variable is kind of tacky. But it's a
		 * minor point, and I wanted to document it.
		 */
	
	/* 1*/	int child;
	/* 2*/	Object tmp = data[ startNode ];
		int hole;

	/* 3*/	for(hole = startNode; hole * 2 <= size; hole = child ) {
	/* 4*/		child = hole * 2;
	/* 5*/		if( child != size &&
	/* 6*/		    comparator.compare(data[ child + 1 ], data[ child ]) < 0 )
			{
	/* 7*/              child++;
			}

	/* 8*/          if( comparator.compare(data[ child ], tmp ) < 0 ) {
	/* 9*/              data[ hole ] = data[ child ];
			} else {
	/*10*/              break;
			}
		}

	/*11*/	data[ hole ] = tmp;
	}




	/// Default capacity of the heap.
	private static final int DEFAULT_CAPACITY = 100;


	/// Number of elements in the heap
	private int size;

	/// The array that stores the heap.
	private Object[] data; 

	///  Comparator used for ordering the elements in the priority queue.
	protected Comparator comparator;



	/**
	 *  Main function that serves as a simple unit test for the
	 *  Binary Heap.
	 */
	public static void main( String[] args ) {
		int numItems = 10000;
		BinaryHeap h = new BinaryHeap(new IntComparator(), numItems );
		int i = 37;

		try {
			for( i = 37; i != 0; i = ( i + 37 ) % numItems ) {
				h.insert( new Integer( i ) );
			}

			for( i = 1; i < numItems; i++ ) {
				if( ((Integer)( h.deleteMin( ) )).intValue( ) != i ) {
					System.out.println( "Oops! " + i );
				}
			}

			for( i = 37; i != 0; i = ( i + 37 ) % numItems )  {
				h.insert( new Integer( i ) );
			}

			h.insert( new Integer( 0 ) );
			i = 9999999;
			h.insert( new Integer( i ) );
			for( i = 0; i < numItems; i++ ) {
				if( ((Integer)( h.deleteMin( ) )).intValue( ) != i ) {
					System.out.println( "Oops! " + i + " " );
				}
			}
		} catch( OverflowException e ) { 
			System.out.println( "Overflow (expected)! " + i  ); 
		}
	}


	
}