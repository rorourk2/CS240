#ifndef Queue_H
#define Queue_H
#include "LinkedList.h"
template <class T>
class Queue{
	private:
		LinkedList<T> *list;
	public:
		Queue(){
			this->list=new LinkedList<T>();
		}
		~Queue(){
			delete this->list;
		}
		bool enqueue(T data){
			return this->list->insert(data);
		}
		T dequeue(){
			T r=this->list->read();
			this->list->remove();
			return r;
		}
		T peek(){
			T r=this->list->read();
			this->list->reset();
			return r;
		}
		bool empty(){
			return this->list->empty();
		}
		void clear(){
			while(this->list->peek()!=NULL){
				this->list->remove();
			}
		}
}



#endif