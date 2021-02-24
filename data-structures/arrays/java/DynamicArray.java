
public class DynamicArray {
  private int capacity;
  private int size;
  private Object[] array;

  public DynamicArray() {
    this.capacity = 16;
    this.size = 0;
    this.array = new Object[this.capacity];
  }

  public DynamicArray(int capacity) {
    this.capacity = capacity;
    this.size = 0;
    this.array = new Object[this.capacity];
  }

  private void resize() {
    int newCapacity = this.capacity * 2;
    Object[] newArray = new Object[newCapacity];
    System.arraycopy(this.array, 0, newArray, 0, this.size);

    this.array = newArray;
    this.capacity = newCapacity;
  }

  public void pushBack(Object element) {
    if (this.size >= this.capacity) {
      this.resize();
    }
    this.array[this.size++] = element;
  }

  public Object popBack() throws Exception {
    if (this.size <= 0) {
      throw new Exception("DynamicArray is empty");
    }
    return this.array[--this.size];
  }

  public Object get(int index) throws Exception {
    if (index < 0 || index >= this.size) {
      throw new Exception("Index out of range");
    }
    return this.array[index];
  }

  public void set(Object element, int index) throws Exception {
    if (index < 0 || index >= this.size) {
      throw new Exception("Index out of range");
    }
    this.array[index] = element;
  }

  public void insert(Object element, int index) throws Exception {
    if (index < 0 || index >= this.size) {
      throw new Exception("Index out of range");
    }
    
    if (this.size >= this.capacity) {
      this.resize();
    }
   
    for (int i = this.size - 1; i >= index; i--) {
      this.array[i + 1] = this.array[i]; 
    }
 
    this.array[index] = element;
    this.size++;  
  }

  public void delete(int index) throws Exception {
    if (index < 0 || index >= this.size) {
      throw new Exception("Index out of range");
    }
    for (int i = index; i < this.size; i++) {
      this.array[i] = this.array[i + 1];
    }
    this.size--;
  }

  public int find(Object element) throws Exception {
    for (int i = 0; i < this.size; i++) {
      if (this.array[i] == element) {
        return i;
      }
    }
    throw new Exception("Element does not exist");
  }
}
