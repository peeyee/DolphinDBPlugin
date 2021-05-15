/*
 * CoreConcept.h
 *
 *  Created on: Apr 20, 2017
 *      Author: dzhou
 */

#ifndef CORECONCEPT_H_
#define CORECONCEPT_H_

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <chrono>
#include <functional>

#include "Types.h"
#include "SmartPointer.h"
#include "Exceptions.h"
#include "Concurrent.h"
#include "LocklessContainer.h"
#include "FlatHashmap.h"
#include "SysIO.h"
#include "DolphinString.h"

#if defined(__GNUC__) && __GNUC__ >= 4
#define LIKELY(x) (__builtin_expect((x), 1))
#define UNLIKELY(x) (__builtin_expect((x), 0))
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::set;
using std::deque;
using std::pair;

class AuthenticatedUser;
class BinaryOperator;
class ByteArrayCodeBuffer;
class Heap;
class Object;
class Operator;
class Statement;
class Param;
class FunctionDef;
class Constant;
class Vector;
class Matrix;
class Table;
class Set;
class Dictionary;
class DFSChunkMeta;
class SQLTransaction;
class SQLContext;
class ColumnRef;
class SymbolBase;
class SymbolBaseManager;
class Output;
class Console;
class Session;
class ConstantMarshall;
class ConstantUnmarshall;
class DebugContext;
class DomainSite;
class DomainSitePool;
class ClusterNodes;
class DomainPartition;
class Domain;
class PartitionGuard;
class Function;
struct TableUpdate;
struct TableUpdateSizer;
struct TableUpdateUrgency;
struct LocalTableUpdate;
struct TopicSubscribe;
class SessionThreadCallGuard;
class ReducerContainer;
class DistributedCall;
class JobProperty;
struct JITCfgNode;
struct InferredType;
struct FunctionSignature;

typedef SmartPointer<AuthenticatedUser> AuthenticatedUserSP;
typedef SmartPointer<ByteArrayCodeBuffer> ByteArrayCodeBufferSP;
typedef SmartPointer<Constant> ConstantSP;
typedef SmartPointer<Vector> VectorSP;
typedef SmartPointer<Matrix> MatrixSP;
typedef SmartPointer<Object> ObjectSP;
typedef SmartPointer<Operator> OperatorSP;
typedef SmartPointer<Statement> StatementSP;
typedef SmartPointer<Param> ParamSP;
typedef SmartPointer<FunctionDef> FunctionDefSP;
typedef SmartPointer<Heap> HeapSP;
typedef SmartPointer<Table> TableSP;
typedef SmartPointer<Set> SetSP;
typedef SmartPointer<Dictionary> DictionarySP;
typedef SmartPointer<DFSChunkMeta> DFSChunkMetaSP;
typedef SmartPointer<SQLTransaction> SQLTransactionSP;
typedef SmartPointer<SQLContext> SQLContextSP;
typedef SmartPointer<ColumnRef> ColumnRefSP;
typedef SmartPointer<SymbolBase> SymbolBaseSP;
typedef SmartPointer<SymbolBaseManager> SymbolBaseManagerSP;
typedef SmartPointer<Output> OutputSP;
typedef SmartPointer<Console> ConsoleSP;
typedef SmartPointer<Session> SessionSP;
typedef SmartPointer<ConstantMarshall> ConstantMarshallSP;
typedef SmartPointer<ConstantUnmarshall> ConstantUnmarshallSP;
typedef SmartPointer<DebugContext> DebugContextSP;
typedef SmartPointer<DomainSite> DomainSiteSP;
typedef SmartPointer<DomainSitePool> DomainSitePoolSP;
typedef SmartPointer<ClusterNodes> ClusterNodesSP;
typedef SmartPointer<DomainPartition> DomainPartitionSP;
typedef SmartPointer<Domain> DomainSP;
typedef SmartPointer<PartitionGuard> PartitionGuardSP;
typedef SmartPointer<TableUpdate> TableUpdateSP;
typedef SmartPointer<GenericBoundedQueue<TableUpdate, TableUpdateSizer, TableUpdateUrgency> > TableUpdateQueueSP;
typedef SmartPointer<TopicSubscribe> TopicSubscribeSP;
typedef SmartPointer<SessionThreadCallGuard> SessionThreadCallGuardSP;
typedef SmartPointer<ReducerContainer> ReducerContainerSP;
typedef SmartPointer<DistributedCall> DistributedCallSP;
typedef SmartPointer<JobProperty> JobPropertySP;
typedef SmartPointer<JITCfgNode> JITCfgNodeSP;
typedef SmartPointer<InferredType> InferredTypeSP;
typedef SmartPointer<FunctionSignature> FunctionSignatureSP;

typedef ConstantSP(*OptrFunc)(const ConstantSP&,const ConstantSP&);
typedef ConstantSP(*SysFunc)(Heap* heap,vector<ConstantSP>& arguments);
typedef ConstantSP(*TemplateOptr)(const ConstantSP&,const ConstantSP&,const string&, OptrFunc);
typedef ConstantSP(*TemplateUserOptr)(Heap* heap, const ConstantSP&,const ConstantSP&, const FunctionDefSP&);
typedef void (*SysProc)(Heap* heap,vector<ConstantSP>& arguments);
typedef std::function<void (StatementSP)> CFGTraversalFunc;

class AuthenticatedUser{
public:
    AuthenticatedUser(const string& userId, long long time, int priority, int parallelism, bool isAdmin, bool isGuest, bool execScript, bool unitTest, bool dbManage,
    		bool tableRead, const set<string>& readTables, const set<string>& deniedReadTables,
			bool tableWrite, const set<string>& writeTables,const set<string>& deniedWriteTables,
			bool viewRead, const set<string>& views, const set<string>& deniedViews,
			bool dbobjCreate, const set<string>& createDBs, const set<string>& deniedCreateDBs, bool dbobjDelete, const set<string>& deleteDBs, const set<string>& deniedDeleteDBs, bool dbOwner);
    AuthenticatedUser(const ConstantSP& userObj);
    ConstantSP toTuple() const ;
    void setLoginNanoTimeStamp(long long t){loginNanoTimestamp_ = t;}
    string getUserId() const {return userId_;}
    long long getLoginNanoTimeStamp() const {return loginNanoTimestamp_;}
    int getMaxJobPriority() const { return priority_;}
    int getMaxJobParallelism() const {return parallelism_;}
    inline bool isAdmin() const {return permissionFlag_ & 1;}
	inline bool isGuest() const { return permissionFlag_ & 2;}
	inline bool canExecScript() const {return permissionFlag_ & 4;}
	inline bool canUnitTest() const {return permissionFlag_ & 8;}
	inline bool canManageDatabase() const {return permissionFlag_ & 16;}
	inline bool canReadTable() const { return permissionFlag_ & 32;}
	inline bool canWriteTable() const { return permissionFlag_ & 64;}
	inline bool canUseView() const { return permissionFlag_ & 128;}
	inline bool canCreateDBObject() const { return permissionFlag_ & 256;}
	inline bool canDeleteDBObject() const { return permissionFlag_ & 512;}
	inline bool isDBOwner() const { return permissionFlag_ & 1024;}
	bool canReadTable(const string& name) const;
	bool canWriteTable(const string& name) const;
	bool canReadView(const string& name) const;
	bool canCreateDBObject(const string& name) const;
	bool canDeleteDBObject(const string& name) const;
	bool isExpired() const {return expired_;}
	void expire();

    static AuthenticatedUserSP createAdminUser();
    static AuthenticatedUserSP createGuestUser();

private:
    string userId_;
    long long loginNanoTimestamp_;
    int priority_;
    int parallelism_;

    /**
     * bit0: isAdmin
     * bit1: isGuest
     * bit2: execute script
     * bit3: unit test
     * bit4: create or delete databases
     * bit5: read tables
     * bit6: write tables
     * bit7: use view functions
     * bit8: create objects in databases
     * bit9: delete objects in databases
     * bit10: dbOwner
     */
    unsigned int permissionFlag_;

    /**
     * bit0: read all tables
     * bit1: write all tables
     * bit2: use all views
     * bit3: create permission on all databases
     * bit4: delete permission on all databases
     *
     */
    unsigned char allFlag_;
    bool expired_;
    unordered_set<string> permissions_;
};

template<class T>
class Array{
public:
	Array(int capacity) : data_(new T[capacity]), size_(0), capacity_(capacity){}
	Array(T* data, int size, int capacity): data_(data), size_(size), capacity_(capacity){}
	Array(const Array<T>& copy) : data_(new T[copy.size_]), size_(copy.size_), capacity_(copy.capacity_){
		data_ = new T[size_];
		memcpy(data_, copy.data_, sizeof(T) * size_);
	}
	~Array(){delete[] data_;}
	Array<T>* copy(){
		T* data = new T[size_];
		memcpy(data, data_, sizeof(T) * size_);
		return new Array(data, size_, capacity_);
	}
	Array<T>& operator =(const Array<T>& sp){
		size_ = sp.size_;
		if(capacity_ >= sp.capacity_){
			memcpy(data_, sp.data_, sizeof(T) * size_);
		}
		else{
			delete[] data_;
			capacity_ = sp.capacity_;
			data_ = new T[capacity_];
			memcpy(data_, sp.data_, sizeof(T) * size_);
		}
		return *this;
	}
	const T& at(int index) const { return data_[index];}
	const T& operator [](int index) const {return data_[index];}
	T& operator [](int index) {return data_[index];}
	const T* getDataReference() const { return data_;}
	bool append(const T& val){
		if(size_ >= capacity_)
			return false;
		data_[size_++] = val;
		return true;
	}
	int size() const {return size_;}
	int capacity() const {return capacity_;}
	void clear(){ size_ = 0;}

private:
	T* data_;
	int size_;
	int capacity_;
};

template<class T>
class DynamicArray{
public:
	DynamicArray(int segmentSizeInBit, int segmentCapacity): dataSegment_(new T*[segmentCapacity]), segmentSize_(1<<segmentSizeInBit),
		segmentSizeInBit_(segmentSizeInBit), segmentMask_((1<<segmentSizeInBit) - 1), segmentCapacity_(segmentCapacity),
		size_(0), sizeInSegment_(0){}
	~DynamicArray(){
		for(int i=0; i<sizeInSegment_; ++i)
			delete[] dataSegment_[i];
		delete[] dataSegment_;
	}
	const T& at(int index) const { return dataSegment_[index >> segmentSizeInBit_][index & segmentMask_];}
	const T& operator [](int index) const { return dataSegment_[index >> segmentSizeInBit_][index & segmentMask_];}
	bool push_back(const T& val){
		if((size_ >> segmentSizeInBit_) + 1 > sizeInSegment_){
			if(sizeInSegment_ >= segmentCapacity_)
				return false;
			else{
				dataSegment_[sizeInSegment_++] = new T[segmentSize_];
			}
		}
		dataSegment_[size_ >> segmentSizeInBit_][size_ & segmentMask_] = val;
		++size_;
		return true;
	}
	int size() const {return size_;}
	int capacity() const {return segmentSize_ * segmentCapacity_;}
	void clear(){
		size_ = 0;
		sizeInSegment_ = 0;
	}
	void get(vector<T>& copy, int size){
		int start =0;
		int s = 0;
		while(start < size){
			int count = std::min(segmentSize_, size - start);
			T* data = dataSegment_[s++];
			for(int i=0; i<count; ++i)
				copy.push_back(data[i]);
			start += count;
		}
	}

private:
	T** dataSegment_;
	int segmentSize_; // the number of elements in one segment. it must be the power of 2, e.g. 2, 4, 8, 16...
	int segmentSizeInBit_;
	int segmentMask_; // 1<<segmentSizeInBit - 1
	int segmentCapacity_; // total number of segments available
	int size_; // the number of elements
	int sizeInSegment_;
};

class ByteArrayCodeBuffer{
public:
	ByteArrayCodeBuffer(size_t capacity) : buf_(new char[capacity]), capacity_(capacity), size_(0), constantMap_(0), constants_(0){}
	ByteArrayCodeBuffer() : buf_(new char[2048]), capacity_(2048), size_(0), constantMap_(0), constants_(0){}
	~ByteArrayCodeBuffer();
	IO_ERR write(const char* buffer, int length, int& actualLength);
	IO_ERR write(const char* buffer, int length);
	IO_ERR write(const ConstantSP& obj);
	inline IO_ERR write(const string& buffer){ return write(buffer.c_str(), buffer.length() + 1);}
	inline IO_ERR write(const DolphinString& buffer){ return write(buffer.c_str(), buffer.length() + 1);}
	inline IO_ERR write(bool val){ return write((const char*)&val, 1);}
	inline IO_ERR write(char val){ return write(&val, 1);}
	inline IO_ERR write(short val){ return write((const char*)&val, 2);}
	inline IO_ERR write(unsigned short val){ return write((const char*)&val, 2);}
	inline IO_ERR write(int val){ return write((const char*)&val, 4);}
	inline IO_ERR write(long long val){ return write((const char*)&val, 8);}
	inline IO_ERR write(float val){ return write((const char*)&val, 4);}
	inline IO_ERR write(double val){ return write((const char*)&val, 8);}
	size_t size() const { return size_;}
	size_t capacity() const { return capacity_;}
	const char * getBuffer() const { return buf_;}
	void clear();
	int getConstantCount() const {return constants_ == 0 ? 0 :constants_->size();}
	const ConstantSP& getConstant(int index) const { return constants_->at(index);}

private:
	char* buf_;
	size_t capacity_;
	size_t size_;
	unordered_map<long long, int>* constantMap_;
	vector<ConstantSP>* constants_;
};

class SymbolBase{
public:
	SymbolBase(bool supportOrder = false);
	SymbolBase(const vector<DolphinString>& symbols, bool supportOrder = false);
	SymbolBase(const string& symbolFile, bool snapshot = false, bool supportOrder=false);
	SymbolBase(const string& symbolFile, const DataInputStreamSP& in, bool snapshot = false);
	SymbolBase* copy();
	bool saveSymbolBase(string& errMsg, bool sync = false);
	IO_ERR serialize(int offset, int length, Buffer& buf);
	inline bool lastSaveSynchronized() const { return lastSaveSynchronized_;}
	inline int find(const DolphinString& symbol){
#ifndef LOCKFREE_SYMBASE
		LockGuard<Mutex> guard(&keyMutex_);
#endif
		int index = -1;
		keyMap_.find(symbol, index);
		return index;
	}
	void find(const char** symbols, int size, int* indices);
	int findAndInsert(const DolphinString& symbol);
	/**
	 * This function will acquire the lock and compare the size with the input argument sizeBeforeInsert.
	 * returns 0 if the size doesn't equal to sizeBeforeInsert.
	 * returns -1 if some of the input symbols are already existed.
	 * returns new symbol size after if everything is OK.
	 */
	int atomicInsert(vector<DolphinString>& symbols, int sizeBeforeInsert);
	void getOrdinalCandidate(const DolphinString& symbol, int& ordinal, SmartPointer<Array<int> >& ordinalBase);
	void getOrdinalCandidate(const DolphinString& symbol1, const DolphinString& symbol2, int& ordinal1, int& ordinal2, SmartPointer<Array<int> >& ordinalBase);
	int* getSortedIndices(bool asc, int& length);
	inline bool supportOrder() const { return supportOrder_;}
	/**
	 * enableOrdinalBase and disableOrdinalBase can't be used in multi-threading environment.
	 */
	void enableOrdinalBase();
	void disableOrdinalBase();
	SmartPointer<Array<int> > getOrdinalBase();
	inline const DolphinString& getSymbol(int index) const { return key_[index];}
	void getSymbols(int offset, int length, vector<DolphinString>& symbols) const;
	int size() const {return  key_.size();}
	/**
	 * checkpoint is used for write transactions. When rolling back a transaction,
	 * one can roll back the in-memory symbol base to the checkpoint.
	 */
	void setCheckpoint(int n);
	inline int getCheckpoint() const { return checkpoint_;}
	const Guid& getID(){return baseID_;}
	bool isModified(){return modified_;}
	int getVersion(){return version_;}
    const string& getDBPath() const {return dbPath_;}
    void setDBPath(const string& dbPath) { dbPath_ = dbPath;}
	static int readSymbolBaseVersion(const string symbolFile);

private:
	int getOrdinalCandidate(const DolphinString& symbol);
	void reAssignOrdinal(int capacity);
	bool reload(const string& symbolFile, const DataInputStreamSP& in, bool snapshot = false);

private:
	Guid baseID_;
	int interval_;
	int version_;
	string dbPath_;
	int savingPoint_;
	int checkpoint_;
	bool modified_;
	bool lastSaveSynchronized_;
	bool supportOrder_;
	DynamicArray<DolphinString> key_;
	SmartPointer<Array<int> > ordinal_;
#ifndef LOCKFREE_SYMBASE
	Mutex keyMutex_;
	IrremovableFlatHashmap<DolphinString, int> keyMap_;
#else
	IrremovableLocklessFlatHashmap<string, int> keyMap_;
#endif
	deque<int> sortedIndices_;
	mutable Mutex writeMutex_;
	mutable Mutex versionMutex_;
};

class SymbolBaseManager{
public:
	SymbolBaseManager(const string& symbolBaseDir);
	SymbolBaseSP findAndLoad(int symBaseID);
	SymbolBaseSP findOrInsert(const string& key);
	SymbolBaseSP find(const string& key);
	void reloadSymbolBase(const string& key);
	string getSymbolFile(const string& key);

private:
	int checkSymbolBaseVersion(const string& key);

private:
	string dir_;
	int devId_;
	unordered_map<string, SymbolBaseSP> symbases_;
	Mutex mutex_;
};

struct ControlFlowEdge {
	void * edgeFrom;
	void * edgeTo;
	string varName;
	ControlFlowEdge(void * from, void * to, const string & name): edgeFrom(from), edgeTo(to), varName(name) {}
	bool operator==(const ControlFlowEdge & rhs) const {
		return edgeFrom == rhs.edgeFrom && edgeTo == rhs.edgeTo && varName == rhs.varName;
	}
};
namespace std {
	template<>
	struct hash<ControlFlowEdge> {
		std::size_t operator()(const  ControlFlowEdge & k) const {
			using std::size_t;
			using std::hash;
			using std::string;
			return hash<void*>{}(k.edgeFrom)
				   ^ (hash<void*>{}(k.edgeTo) >> 1)
				   ^ (hash<string>{}(k.varName) << 1);
		}
	};
}

struct FunctionSignature {
	InferredTypeSP returnTy;
	vector<InferredTypeSP> paramTys;
	vector<int> missingParams;
	FunctionDef* func;
	void* jitFunc;
	Function* funcObj;

	FunctionSignature() : func(0), jitFunc(0), funcObj(0){}
};

struct InferredType {
    DATA_FORM form;
    DATA_TYPE type;
    DATA_CATEGORY category;
    FunctionSignatureSP signature;

    InferredType(DATA_FORM form = DF_SCALAR, DATA_TYPE type = DT_VOID, DATA_CATEGORY category = NOTHING):
        form(form), type(type), category(category){}
    bool operator ==(const InferredType & rhs) const {
        return form == rhs.form && type == rhs.type && category == rhs.category;
    }
    bool operator !=(const InferredType & rhs) const {
        return !operator==(rhs);
    }
    string getString();
};

namespace std {
	template<>
	struct hash<InferredType> {
		std::size_t operator()(const InferredType & k) const {
			using std::size_t;
			using std::hash;
			using std::string;
			return hash<int8_t>{}(k.form) ^ hash<int8_t>{}(k.type);
		}
	};
}

class Object {
public:
	bool isConstant() const {return getObjectType()==CONSTOBJ;}
	bool isVariable() const {return getObjectType()==VAR;}
	virtual ConstantSP getValue(Heap* pHeap) = 0;
	virtual ConstantSP getReference(Heap* pHeap) = 0;
	virtual OBJECT_TYPE getObjectType() const = 0;
	virtual ~Object(){}
	virtual string getScript() const = 0;
	virtual IO_ERR serialize(Heap* pHeap, const ByteArrayCodeBufferSP& buffer) const = 0;
	virtual void collectUserDefinedFunctions(unordered_map<string,FunctionDef*>& functionDefs) const {}
	virtual void collectVariables(vector<int>& vars, int minIndex, int maxIndex) const {}
	virtual bool isLargeConstant() const {return false;}
};

class Constant: public Object{
public:
	static DolphinString DEMPTY;
	static string EMPTY;
	static string NULL_STR;

	Constant() : flag_(3){}
	Constant(unsigned short flag) :  flag_(flag){}
	virtual ~Constant(){}
	inline bool isTemporary() const {return flag_ & 1;}
	inline void setTemporary(bool val){ if(val) flag_ |= 1; else flag_ &= ~1;}
	inline bool isIndependent() const {return flag_ & 2;}
	inline void setIndependent(bool val){ if(val) flag_ |= 2; else flag_ &= ~2;}
	inline bool isReadOnly() const {return flag_ & 4;}
	inline void setReadOnly(bool val){ if(val) flag_ |= 4; else flag_ &= ~4;}
	inline bool isReadOnlyArgument() const {return flag_ & 8;}
	inline void setReadOnlyArgument(bool val){ if(val) flag_ |= 8; else flag_ &= ~8;}
	inline bool isNothing() const {return flag_ & 16;}
	inline void setNothing(bool val){ if(val) flag_ |= 16; else flag_ &= ~16;}
	inline bool isStatic() const {return flag_ & 32;}
	inline void setStatic(bool val){ if(val) flag_ |= 32; else flag_ &= ~32;}
	inline bool transferAsString() const {return flag_ & 64;}
	inline void transferAsString(bool val){ if(val) flag_ |= 64; else flag_ &= ~64;}
	inline bool isSynchronized() const {return flag_ & 128;}
	inline void setSynchronized(bool val){ if(val) flag_ |= 128; else flag_ &= ~128;}
	inline bool isOOInstance() const {return flag_ & 4096;}
	inline void setOOInstance(bool val){ if(val) flag_ |= 4096; else flag_ &= ~4096;}
	inline bool isIndexed() const {return flag_ & 8192;}
	inline void setIndexed(bool val){ if(val) flag_ |= 8192; else flag_ &= ~8192;}
	inline bool isSeries() const {return flag_ & 16384;}
	inline void setSeries(bool val){ if(val) flag_ |= 16384; else flag_ &= ~16384;}
	inline DATA_FORM getForm() const {return DATA_FORM((flag_ >> 8) & 15);}
	inline void setForm(DATA_FORM df){ flag_ = (flag_ & 61695) + (df << 8);}
	inline bool isScalar() const { return getForm()==DF_SCALAR;}
	inline bool isArray() const { return getForm()==DF_VECTOR;}
	inline bool isPair() const { return getForm()==DF_PAIR;}
	inline bool isMatrix() const {return getForm()==DF_MATRIX;}
	//a vector could be array, pair or matrix.
	inline bool isVector() const { return getForm()>=DF_VECTOR && getForm()<=DF_MATRIX;}
	inline bool isTable() const { return getForm()==DF_TABLE;}
	inline bool isSet() const {return getForm()==DF_SET;}
	inline bool isDictionary() const {return getForm()==DF_DICTIONARY;}
	inline bool isChunk() const {return getForm()==DF_CHUNK;}
	bool isTuple() const {return getForm()==DF_VECTOR && getType()==DT_ANY;}
	bool isNumber() const { DATA_CATEGORY cat = getCategory(); return cat == INTEGRAL || cat == FLOATING;}

	virtual bool isDatabase() const {return false;}
	virtual char getBool() const {throw RuntimeException("The object can't be converted to boolean scalar.");}
	virtual char getChar() const {throw RuntimeException("The object can't be converted to char scalar.");}
	virtual short getShort() const {throw RuntimeException("The object can't be converted to short scalar.");}
	virtual int getInt() const {throw RuntimeException("The object can't be converted to int scalar.");}
	virtual long long  getLong() const {throw RuntimeException("The object can't be converted to long scalar.");}
	virtual INDEX getIndex() const {throw RuntimeException("The object can't be converted to index scalar.");}
	virtual float getFloat() const {throw RuntimeException("The object can't be converted to float scalar.");}
	virtual double getDouble() const {throw RuntimeException("The object can't be converted to double scalar.");}
	virtual string getString() const {return "";}
	virtual string getScript() const { return getString();}
	virtual const DolphinString& getStringRef() const {return DEMPTY;}
    virtual const Guid getInt128() const {throw RuntimeException("The object can't be converted to int128 scalar.");}
    virtual const unsigned char* getBinary() const {throw RuntimeException("The object can't be converted to int128 scalar.");}
	virtual bool isNull() const {return false;}

	virtual void setBool(char val){}
	virtual void setChar(char val){}
	virtual void setShort(short val){}
	virtual void setInt(int val){}
	virtual void setLong(long long val){}
	virtual void setIndex(INDEX val){}
	virtual void setFloat(float val){}
	virtual void setDouble(double val){}
	virtual void setString(const DolphinString& val){}
	virtual void setBinary(const unsigned char* val, int unitLength){}
	virtual void setNull(){}

	virtual char getBool(INDEX index) const {return getBool();}
	virtual char getChar(INDEX index) const { return getChar();}
	virtual short getShort(INDEX index) const { return getShort();}
	virtual int getInt(INDEX index) const {return getInt();}
	virtual long long getLong(INDEX index) const {return getLong();}
	virtual INDEX getIndex(INDEX index) const {return getIndex();}
	virtual float getFloat(INDEX index) const {return getFloat();}
	virtual double getDouble(INDEX index) const {return getDouble();}
	virtual string getString(INDEX index) const {return getString();}
	virtual const DolphinString& getStringRef(INDEX index) const {return DEMPTY;}
	virtual bool isNull(INDEX index) const {return isNull();}

	virtual ConstantSP get(INDEX index) const {return getValue();}
	virtual ConstantSP get(INDEX column, INDEX row) const {return get(row);}
	virtual ConstantSP get(const ConstantSP& index) const {return getValue();}
	virtual ConstantSP getColumn(INDEX index) const {return getValue();}
	virtual ConstantSP getRow(INDEX index) const {return get(index);}
	virtual ConstantSP getItem(INDEX index) const {return get(index);}
	virtual ConstantSP getItems(const ConstantSP& index) const {return get(index);}
	virtual ConstantSP getWindow(INDEX colStart, int colLength, INDEX rowStart, int rowLength) const {return getValue();}
	virtual ConstantSP getSlice(const ConstantSP& rowIndex, const ConstantSP& colIndex) const {throw RuntimeException("getSlice method not supported");}
	virtual ConstantSP getRowLabel() const;
	virtual ConstantSP getColumnLabel() const;

	virtual bool isNull(INDEX start, int len, char* buf) const {return false;}
	virtual bool isValid(INDEX start, int len, char* buf) const {return false;}
	virtual bool getBool(INDEX start, int len, char* buf) const {return false;}
	virtual bool getChar(INDEX start, int len,char* buf) const {return false;}
	virtual bool getShort(INDEX start, int len, short* buf) const {return false;}
	virtual bool getInt(INDEX start, int len, int* buf) const {return false;}
	virtual bool getLong(INDEX start, int len, long long* buf) const {return false;}
	virtual bool getIndex(INDEX start, int len, INDEX* buf) const {return false;}
	virtual bool getFloat(INDEX start, int len, float* buf) const {return false;}
	virtual bool getDouble(INDEX start, int len, double* buf) const {return false;}
	virtual bool getSymbol(INDEX start, int len, int* buf, SymbolBase* symBase,bool insertIfNotThere) const {return false;}
	virtual bool getString(INDEX start, int len, DolphinString** buf) const {return false;}
	virtual bool getString(INDEX start, int len, char** buf) const {return false;}
	virtual bool getBinary(INDEX start, int len, int unitLength, unsigned char* buf) const {return false;}

	virtual bool isNull(INDEX* indices, int len, char* buf) const {return false;}
	virtual bool isValid(INDEX* indices, int len, char* buf) const {return false;}
	virtual bool getBool(INDEX* indices, int len, char* buf) const {return false;}
	virtual bool getChar(INDEX* indices, int len,char* buf) const {return false;}
	virtual bool getShort(INDEX* indices, int len, short* buf) const {return false;}
	virtual bool getInt(INDEX* indices, int len, int* buf) const {return false;}
	virtual bool getLong(INDEX* indices, int len, long long* buf) const {return false;}
	virtual bool getIndex(INDEX* indices, int len, INDEX* buf) const {return false;}
	virtual bool getFloat(INDEX* indices, int len, float* buf) const {return false;}
	virtual bool getDouble(INDEX* indices, int len, double* buf) const {return false;}
	virtual bool getSymbol(INDEX* indices, int len, int* buf, SymbolBase* symBase,bool insertIfNotThere) const {return false;}
	virtual bool getString(INDEX* indices, int len, DolphinString** buf) const {return false;}
	virtual bool getString(INDEX* indices, int len, char** buf) const {return false;}
	virtual bool getBinary(INDEX* indices, int len, int unitLength, unsigned char* buf) const {return false;}

	virtual const char* getBoolConst(INDEX start, int len, char* buf) const {throw RuntimeException("getBoolConst method not supported");}
	virtual const char* getCharConst(INDEX start, int len,char* buf) const {throw RuntimeException("getCharConst method not supported");}
	virtual const short* getShortConst(INDEX start, int len, short* buf) const {throw RuntimeException("getShortConst method not supported");}
	virtual const int* getIntConst(INDEX start, int len, int* buf) const {throw RuntimeException("getIntConst method not supported");}
	virtual const long long* getLongConst(INDEX start, int len, long long* buf) const {throw RuntimeException("getLongConst method not supported");}
	virtual const INDEX* getIndexConst(INDEX start, int len, INDEX* buf) const {throw RuntimeException("getIndexConst method not supported");}
	virtual const float* getFloatConst(INDEX start, int len, float* buf) const {throw RuntimeException("getFloatConst method not supported");}
	virtual const double* getDoubleConst(INDEX start, int len, double* buf) const {throw RuntimeException("getDoubleConst method not supported");}
	virtual const int* getSymbolConst(INDEX start, int len, int* buf, SymbolBase* symBase, bool insertIfNotThere) const {throw RuntimeException("getSymbolConst method not supported");}
	virtual DolphinString** getStringConst(INDEX start, int len, DolphinString** buf) const {throw RuntimeException("getStringConst method not supported");}
	virtual char** getStringConst(INDEX start, int len, char** buf) const {throw RuntimeException("getStringConst method not supported");}
	virtual const unsigned char* getBinaryConst(INDEX start, int len, int unitLength, unsigned char* buf) const {throw RuntimeException("getBinaryConst method not supported");}

	virtual char* getBoolBuffer(INDEX start, int len, char* buf) const {return buf;}
	virtual char* getCharBuffer(INDEX start, int len,char* buf) const {return buf;}
	virtual short* getShortBuffer(INDEX start, int len, short* buf) const {return buf;}
	virtual int* getIntBuffer(INDEX start, int len, int* buf) const {return NULL;}
	virtual long long* getLongBuffer(INDEX start, int len, long long* buf) const {return buf;}
	virtual INDEX* getIndexBuffer(INDEX start, int len, INDEX* buf) const {return buf;}
	virtual float* getFloatBuffer(INDEX start, int len, float* buf) const {return buf;}
	virtual double* getDoubleBuffer(INDEX start, int len, double* buf) const {return buf;}
	virtual unsigned char* getBinaryBuffer(INDEX start, int len, int unitLength, unsigned char* buf) const {return buf;}
	virtual void* getDataBuffer(INDEX start, int len, void* buf) const {return buf;}

	virtual IO_ERR serialize(Heap* pHeap, const ByteArrayCodeBufferSP& buffer) const {return serialize(buffer);}
	virtual IO_ERR serialize(const ByteArrayCodeBufferSP& buffer) const {throw RuntimeException("code serialize method not supported");}
    virtual int serialize(char* buf, int bufSize, INDEX indexStart, int offset, int& numElement, int& partial) const {throw RuntimeException("serialize method not supported");}
    virtual IO_ERR deserialize(DataInputStream* in, INDEX indexStart, int offset, INDEX targetNumElement, INDEX& numElement, int& partial) {throw RuntimeException("deserialize method not supported");}

	virtual void nullFill(const ConstantSP& val){}
	virtual void setBool(INDEX index,bool val){setBool(val);}
	virtual void setChar(INDEX index,char val){setChar(val);}
	virtual void setShort(INDEX index,short val){setShort(val);}
	virtual void setInt(INDEX index,int val){setInt(val);}
	virtual void setLong(INDEX index,long long val){setLong(val);}
	virtual void setIndex(INDEX index,INDEX val){setIndex(val);}
	virtual void setFloat(INDEX index,float val){setFloat(val);}
	virtual void setDouble(INDEX index, double val){setDouble(val);}
	virtual void setString(INDEX index, const DolphinString& val){setString(val);}
	virtual void setBinary(INDEX index, int unitLength, const unsigned char* val){setBinary(val, unitLength);}
	virtual void setNull(INDEX index){setNull();}

	virtual bool set(INDEX index, const ConstantSP& value){return false;}
	virtual bool set(INDEX column, INDEX row, const ConstantSP& value){return false;}
	virtual bool set(const ConstantSP& index, const ConstantSP& value) {return false;}
	virtual bool setNonNull(const ConstantSP& index, const ConstantSP& value) {return false;}
	virtual bool setItem(INDEX index, const ConstantSP& value){return set(index,value);}
	virtual bool setColumn(INDEX index, const ConstantSP& value){return assign(value);}
	virtual void setRowLabel(const ConstantSP& label){}
	virtual void setColumnLabel(const ConstantSP& label){}
	virtual bool reshape(INDEX cols, INDEX rows) {return false;}
	virtual bool assign(const ConstantSP& value){return false;}

	virtual bool setBool(INDEX start, int len, const char* buf){return false;}
	virtual bool setChar(INDEX start, int len, const char* buf){return false;}
	virtual bool setShort(INDEX start, int len, const short* buf){return false;}
	virtual bool setInt(INDEX start, int len, const int* buf){return false;}
	virtual bool setLong(INDEX start, int len, const long long* buf){return false;}
	virtual bool setIndex(INDEX start, int len, const INDEX* buf){return false;}
	virtual bool setFloat(INDEX start, int len, const float* buf){return false;}
	virtual bool setDouble(INDEX start, int len, const double* buf){return false;}
	virtual bool setString(INDEX start, int len, const string* buf){return false;}
	virtual bool setString(INDEX start, int len, char** buf){return false;}
	virtual bool setBinary(INDEX start, int len, int unitLength, const unsigned char* buf){return false;}
	virtual bool setData(INDEX start, int len, void* buf) {return false;}

	virtual bool add(INDEX start, INDEX length, long long inc) { return false;}
	virtual bool add(INDEX start, INDEX length, double inc) { return false;}
	virtual void validate() {}

	virtual int compare(INDEX index, const ConstantSP& target) const {return 0;}

	virtual bool getNullFlag() const {return isNull();}
	virtual void setNullFlag(bool containNull){}
	virtual bool hasNull(){return  isNull();}
	virtual bool hasNull(INDEX start, INDEX length){return isNull();}
	virtual bool sizeable() const {return false;}
	virtual bool copyable() const {return true;}
	virtual INDEX size() const {return 1;}
	virtual INDEX itemCount() const {return getForm()==DF_MATRIX?columns():size();}
	virtual INDEX rows() const {return size();}
	virtual INDEX uncompressedRows() const {return size();}
	virtual INDEX columns() const {return 1;};
	virtual ConstantSP getMember(const ConstantSP& key) const { throw RuntimeException("getMember method not supported");}
	virtual ConstantSP keys() const {throw RuntimeException("keys method not supported");}
	virtual ConstantSP values() const {throw RuntimeException("values method not supported");}
	virtual ConstantSP callMethod(const string& name, Heap* heap, vector<ConstantSP>& args) const {throw RuntimeException("callMethod method not supported");}

	virtual long long releaseMemory(long long target, bool& satisfied) { satisfied = false; return 0;}
	virtual long long getAllocatedMemory() const {return 0;}
	virtual DATA_TYPE getType() const =0;
	virtual DATA_TYPE getRawType() const =0;
	virtual int getExtraParamForType() const { return 0;}
	virtual DATA_CATEGORY getCategory() const =0;

	virtual ConstantSP getInstance() const =0;
	virtual ConstantSP getValue() const =0;
	virtual ConstantSP getValue (Heap* pHeap){return getValue();}
	virtual ConstantSP getReference(Heap* pHeap){return getValue();}
	virtual OBJECT_TYPE getObjectType() const {return CONSTOBJ;}
	virtual SymbolBaseSP getSymbolBase() const {return SymbolBaseSP();}
	virtual void contain(const ConstantSP& target, const ConstantSP& resultSP) const {throw RuntimeException("contain method not supported");}
	virtual bool isFastMode() const {return false;}
	virtual void* getDataArray() const {return 0;}
	virtual void** getDataSegment() const {return 0;}
	virtual bool isIndexArray() const { return false;}
	virtual INDEX* getIndexArray() const { return NULL;}
	virtual bool isHugeIndexArray() const { return false;}
	virtual INDEX** getHugeIndexArray() const { return NULL;}
	virtual int getSegmentSize() const { return 1;}
	virtual int getSegmentSizeInBit() const { return 0;}
	virtual bool containNotMarshallableObject() const {return false;}

private:
	unsigned short flag_;
};

class Vector:public Constant{
public:
	Vector(): Constant(259){}
	virtual ~Vector(){}
	virtual ConstantSP getColumnLabel() const;
	const string& getName() const {return name_;}
	void setName(const string& name){name_=name;}
	virtual bool isLargeConstant() const { return isMatrix() || size()>1024; }
	virtual bool isView() const {return false;}
	virtual bool isRepeatingVector() const {return false;}
	virtual void initialize(){}
	virtual INDEX getCapacity() const = 0;
	virtual	INDEX reserve(INDEX capacity) {throw RuntimeException("Vector::reserve method not supported");}
	virtual	void resize(INDEX size) {throw RuntimeException("Vector::resize method not supported");}
	virtual short getUnitLength() const = 0;
	virtual void clear()=0;
	virtual bool remove(INDEX count){return false;}
	virtual bool remove(const ConstantSP& index){return false;}
	virtual bool append(const ConstantSP& value){return append(value, value->size());}
	virtual bool append(const ConstantSP& value, INDEX count){return false;}
	virtual bool appendBool(char* buf, int len){return false;}
	virtual bool appendChar(char* buf, int len){return false;}
	virtual bool appendShort(short* buf, int len){return false;}
	virtual bool appendInt(int* buf, int len){return false;}
	virtual bool appendLong(long long* buf, int len){return false;}
	virtual bool appendIndex(INDEX* buf, int len){return false;}
	virtual bool appendFloat(float* buf, int len){return false;}
	virtual bool appendDouble(double* buf, int len){return false;}
	virtual bool appendString(string* buf, int len){return false;}
	virtual bool appendString(char** buf, int len){return false;}
	virtual bool appendGuid(Guid* buf, int len){return appendBinary((unsigned char*)buf, len, 16);}
	virtual bool appendBinary(unsigned char* buf, int len, int unitLength){return false;}
	virtual string getString() const;
	virtual string getScript() const;
	virtual string getString(INDEX index) const = 0;
	virtual ConstantSP getInstance() const {return getInstance(size());}
	virtual ConstantSP getInstance(INDEX size) const = 0;
	virtual ConstantSP getValue(INDEX capacity) const {throw RuntimeException("Vector::getValue method not supported");}
	virtual ConstantSP get(INDEX column, INDEX rowStart,INDEX rowEnd) const {return getSubVector(column*rows()+rowStart,rowEnd-rowStart);}
	virtual ConstantSP get(INDEX index) const = 0;
	virtual ConstantSP getWindow(INDEX colStart, int colLength, INDEX rowStart, int rowLength) const {return getSubVector(rowStart,rowLength);}
	virtual ConstantSP getSubVector(INDEX start, INDEX length) const { throw RuntimeException("getSubVector method not supported");}
	virtual ConstantSP getSubVector(INDEX start, INDEX length, INDEX capacity) const { return getSubVector(start, length);}
	virtual void fill(INDEX start, INDEX length, const ConstantSP& value)=0;
	virtual void next(INDEX steps)=0;
	virtual void prev(INDEX steps)=0;
	virtual void reverse()=0;
	virtual void reverse(INDEX start, INDEX length)=0;
	virtual void shuffle(){}
	virtual void replace(const ConstantSP& oldVal, const ConstantSP& newVal){}
	virtual bool validIndex(INDEX uplimit){return false;}
	virtual bool validIndex(INDEX start, INDEX length, INDEX uplimit){return false;}
	virtual void addIndex(INDEX start, INDEX length, INDEX offset){}
	virtual void neg()=0;
	virtual void find(INDEX start, INDEX length, const ConstantSP& target, const ConstantSP& resultSP){}
	virtual void find(const ConstantSP& target, const ConstantSP& resultSP){
		find(0, size(), target, resultSP);
	}
	virtual void binarySearch(INDEX start, INDEX length, const ConstantSP& target, const ConstantSP& resultSP){}
	virtual void binarySearch(const ConstantSP& target, const ConstantSP& resultSP){
		binarySearch(0, size(), target, resultSP);
	}
	virtual void asof(INDEX start, INDEX length, const ConstantSP& target, const ConstantSP& resultSP){ throw RuntimeException("asof method not supported.");}
	virtual void asof(const ConstantSP& target, const ConstantSP& resultSP){
		asof(0, size(), target, resultSP);
	}
	virtual void upper(){throw RuntimeException("upper method not supported");}
	virtual void lower(){throw RuntimeException("lower method not supported");}
	virtual void trim(){throw RuntimeException("trim method not supported");}
	virtual void strip(){throw RuntimeException("strip method not supported");}
	virtual long long count() const = 0;
	virtual long long count(INDEX start, INDEX length) const = 0;
	virtual ConstantSP minmax() const;
	virtual ConstantSP minmax(INDEX start, INDEX length) const;
	virtual ConstantSP max() const = 0;
	virtual ConstantSP max(INDEX start, INDEX length) const = 0;
	virtual INDEX imax() const = 0;
	virtual INDEX imax(INDEX start, INDEX length) const = 0;
	virtual ConstantSP min() const = 0;
	virtual ConstantSP min(INDEX start, INDEX length) const = 0;
	virtual INDEX imin() const = 0;
	virtual INDEX imin(INDEX start, INDEX length) const = 0;
	virtual ConstantSP avg() const = 0;
	virtual ConstantSP avg(INDEX start, INDEX length) const = 0;
	virtual ConstantSP sum() const = 0;
	virtual ConstantSP sum(INDEX start, INDEX length) const = 0;
	virtual ConstantSP sum2() const = 0;
	virtual ConstantSP sum2(INDEX start, INDEX length) const = 0;
	virtual ConstantSP prd() const = 0;
	virtual ConstantSP prd(INDEX start, INDEX length) const = 0;
	virtual ConstantSP var() const = 0;
	virtual ConstantSP var(INDEX start, INDEX length) const = 0;
	virtual ConstantSP std() const = 0;
	virtual ConstantSP std(INDEX start, INDEX length) const = 0;
	virtual ConstantSP median() const = 0;
	virtual ConstantSP median(INDEX start, INDEX length) const = 0;
	virtual ConstantSP searchK(INDEX k) const {throw RuntimeException("searchK method not supported");}
	virtual ConstantSP searchK(INDEX start, INDEX length, INDEX k) const {throw RuntimeException("searchK method not supported");}
	virtual ConstantSP mode() const = 0;
	virtual ConstantSP mode(INDEX start, INDEX length) const = 0;
	virtual ConstantSP stat() const;
	virtual ConstantSP stat(INDEX start, INDEX length) const;
	virtual ConstantSP firstNot(const ConstantSP& exclude) const = 0;
	virtual ConstantSP firstNot(INDEX start, INDEX length, const ConstantSP& exclude) const = 0;
	virtual ConstantSP lastNot(const ConstantSP& exclude) const = 0;
	virtual ConstantSP lastNot(INDEX start, INDEX length, const ConstantSP& exclude) const = 0;
	virtual bool isSorted(bool asc, bool strict = false) const { return isSorted(0, size(), asc, strict);}
	virtual bool isSorted(INDEX start, INDEX length, bool asc, bool strict = false) const = 0;

	/**
	 * Find the first element that is no less than the target value in the sorted vector.
	 * start: the starting point of the search.
	 */
	virtual INDEX lowerBound(INDEX start, const ConstantSP& target)=0;

	virtual bool equalToPrior(INDEX start, INDEX length, bool* result){ return false;}
	virtual bool equalToPrior(INDEX prior, const INDEX* indices, INDEX length, bool* result){ return false;}
	virtual ConstantSP topK(INDEX start, INDEX length, INDEX top, bool asc, bool extendEqualValue) {throw RuntimeException("topK method not supported");}
	virtual ConstantSP topK(INDEX top, bool asc, bool extendEqualValue) {
		return topK(0, size(), top, asc, extendEqualValue);
	}
	/**
	 * Sort the whole vector with given order
	 * asc: indicating if it is ascending order
	 */
	virtual bool sort(bool asc) = 0;

	/**
	 * Sort the vector and the corresponding indices with given order
	 * asc: indicating if it is ascending order
	 * indices: the corresponding indices of the data to sort.The length of the data should be equal to
	 * the length of the indices. The indices will be rearranged accordingly during sorting
	 */
	virtual bool sort(bool asc, Vector* indices) = 0;

	virtual INDEX sortTop(bool asc, Vector* indices, INDEX top) {throw RuntimeException("sortTop method not supported");}

	/**
	 * Sort the selected indices based on the corresponding data with given order.
	 * indices: the selected indices to sort
	 * start: the start position in indices vector
	 * length: the number of indices to sort
	 * asc: indicating if it is ascending order
	 */
	virtual bool sortSelectedIndices(Vector* indices, INDEX start, INDEX length, bool asc) = 0;

    /**
     * Find duplicated elements in an ascending-sorted array
     * indices: indices of data to search. The underlying data was not sorted. However the indices
     *     are in the ascending order
     * start: the start position in indices vector
     * length: the number of indices to process
     * duplicates: output vector of the duplicated elements. pair.first stores the starting position
     *     of the duplicated elements in the indices array and pair.second has the number of duplicated elements.
     */
	virtual bool findDuplicatedElements(Vector* indices, INDEX start, INDEX length, vector<pair<INDEX,INDEX> >& duplicates) = 0;

	/**
	 * Find duplicated elements in the segment of an ascending-sorted array
	 * start: the starting position of the segment
	 * length: the length of the segment.
     * duplicates: output vector of the duplicated elements. pair.first stores the starting position
     *     of the duplicated elements in the array and pair.second has the number of duplicated elements.
	 */
	virtual bool findDuplicatedElements(INDEX start, INDEX length, vector<pair<INDEX,INDEX> >& duplicates)=0;

	virtual bool findUniqueElements(INDEX start, INDEX length, vector<pair<INDEX,INDEX> >& uniques)=0;

	virtual bool findRange(INDEX* ascIndices,const ConstantSP& target,INDEX* targetIndices,vector<pair<INDEX,INDEX> >& ranges)=0;
	virtual bool findRange(const ConstantSP& target,INDEX* targetIndices,vector<pair<INDEX,INDEX> >& ranges)=0;
	virtual long long getAllocatedMemory(INDEX size) const {return Constant::getAllocatedMemory();}

private:
	string name_;
};

class Matrix{
public:
	Matrix(int cols, int rows);
	virtual ~Matrix(){}
	void setRowLabel(const ConstantSP& label);
	void setColumnLabel(const ConstantSP& label);
	bool reshape(INDEX cols, INDEX rows);
	string getString() const;
	string getString(INDEX index) const ;
	ConstantSP get(const ConstantSP& index) const ;
	bool set(const ConstantSP index, const ConstantSP& value);
	virtual string getString(int column, int row) const = 0;
	virtual ConstantSP getInstance(INDEX size) const = 0;
	virtual ConstantSP getColumn(INDEX index) const = 0;
	virtual bool setColumn(INDEX index, const ConstantSP& value)=0;
protected:
	int cols_;
	int rows_;
	ConstantSP rowLabel_;
	ConstantSP colLabel_;
};

class Set: public Constant {
public:
	Set() : Constant(1027){}
	virtual ~Set() {}
	virtual void clear()=0;
	virtual bool remove(const ConstantSP& value) = 0;
	virtual bool append(const ConstantSP& value) = 0;
	virtual bool inverse(const ConstantSP& value) = 0;
	virtual void contain(const ConstantSP& target, const ConstantSP& resultSP) const = 0;
	virtual bool isSuperset(const ConstantSP& target) const = 0;
	virtual ConstantSP interaction(const ConstantSP& target) const = 0;
	virtual ConstantSP getSubVector(INDEX start, INDEX length) const = 0;
	virtual string getScript() const {return "set()";}
	virtual bool isLargeConstant() const {return true;}
	virtual void* getRawSet() const = 0;
};

class Dictionary:public Constant{
public:
	Dictionary() : Constant(1283), lock_(0){}
	virtual ~Dictionary();
	virtual INDEX size() const = 0;
	virtual INDEX count() const = 0;
	virtual void clear()=0;
	virtual ConstantSP getMember(const ConstantSP& key) const =0;
	virtual ConstantSP getMember(const string& key) const {throw RuntimeException("String key not supported");}
	virtual ConstantSP get(INDEX column, INDEX row){throw RuntimeException("Dictionary does not support cell function");}
	virtual SymbolBaseSP getKeySymbolBase() const { return nullptr;}
	virtual DATA_TYPE getKeyType() const = 0;
	virtual DATA_CATEGORY getKeyCategory() const = 0;
	virtual DATA_TYPE getType() const = 0;
	virtual DATA_CATEGORY getCategory() const = 0;
	virtual ConstantSP keys() const = 0;
	virtual ConstantSP values() const = 0;
	virtual string getString() const = 0;
	virtual string getScript() const {return "dict()";}
	virtual string getString(int index) const {throw RuntimeException("Dictionary::getString(int index) not supported");}
	virtual bool remove(const ConstantSP& key) = 0;
	virtual bool set(const ConstantSP& key, const ConstantSP& value)=0;
	virtual bool set(const string& key, const ConstantSP& value){throw RuntimeException("String key not supported");}
	virtual bool reduce(BinaryOperator& optr, const ConstantSP& key, const ConstantSP& value)=0;
	virtual bool reduce(Heap* heap, const FunctionDefSP& optr, const FunctionDefSP& initOptr, const ConstantSP& key, const ConstantSP& value)=0;
	virtual ConstantSP get(const ConstantSP& key) const {return getMember(key);}
	virtual void contain(const ConstantSP& target, const ConstantSP& resultSP) const = 0;
	virtual bool isLargeConstant() const {return true;}
	virtual void* getRawMap() const = 0;
	inline Mutex* getLock() const { return lock_;}
	inline void setLock(Mutex* lock) { lock_ = lock;}

private:
	Mutex* lock_;
};

class Table: public Constant{
public:
	Table() : Constant(1539), flag_(0), lock_(0){}
	virtual ~Table();
	virtual string getScript() const {return getName();}
	virtual ConstantSP getColumn(const string& name) const = 0;
	virtual ConstantSP getColumn(const string& qualifier, const string& name) const = 0;
	virtual ConstantSP getColumn(INDEX index) const = 0;
	virtual ConstantSP getColumn(const string& name, const ConstantSP& rowFilter) const = 0;
	virtual ConstantSP getColumn(const string& qualifier, const string& name, const ConstantSP& rowFilter) const = 0;
	virtual ConstantSP getColumn(INDEX index, const ConstantSP& rowFilter) const = 0;
	virtual INDEX columns() const = 0;
	virtual const string& getColumnName(int index) const = 0;
	virtual const string& getColumnQualifier(int index) const = 0;
	virtual void setColumnName(int index, const string& name)=0;
	virtual int getColumnIndex(const string& name) const = 0;
	virtual DATA_TYPE getColumnType(int index) const = 0;
	virtual bool contain(const string& name) const = 0;
	virtual bool contain(const string& qualifier, const string& name) const = 0;
	virtual bool contain(ColumnRef* col) const = 0;
	virtual bool contain(const ColumnRefSP& col) const = 0;
	virtual bool containAll(const vector<ColumnRefSP>& cols) const = 0;
	virtual void setName(const string& name)=0;
	virtual const string& getName() const = 0;
	virtual ConstantSP get(INDEX index) const {return getColumn(index);}
	virtual ConstantSP get(const ConstantSP& index) const = 0;
	virtual ConstantSP getValue(INDEX capacity) const = 0;
	virtual ConstantSP getValue() const = 0;
	virtual ConstantSP getInstance(INDEX size) const = 0;
	virtual INDEX size() const = 0;
	virtual bool sizeable() const = 0;
	virtual string getString(INDEX index) const = 0;
	virtual string getString() const = 0;
	virtual ConstantSP getWindow(INDEX colStart, int colLength, INDEX rowStart, int rowLength) const = 0;
	virtual ConstantSP getMember(const ConstantSP& key) const = 0;
	virtual ConstantSP values() const = 0;
	virtual ConstantSP keys() const = 0;
	virtual TABLE_TYPE getTableType() const = 0;
	virtual bool join(vector<ConstantSP>& columns) { return false;}
	virtual	bool clear() { return false;}
	virtual bool reorderColumns(const vector<int>& newOrders) { return false;}
	virtual bool replaceColumn(int index, const ConstantSP& col) {return false;}
	virtual bool drop(vector<int>& columns) {return false;}
	virtual void remove(Heap* heap, const SQLContextSP& context, const ConstantSP& filterExprs) {throw RuntimeException("Table::remove() not supported");}
	virtual void sortBy(Heap* heap, const ObjectSP& sortExpr, const ConstantSP& sortOrder) {throw RuntimeException("Table::sortBy() not supported");}
	virtual void update(Heap* heap, const SQLContextSP& context, const ConstantSP& updateColNames, const ObjectSP& updateExpr, const ConstantSP& filterExprs) {throw RuntimeException("Table::update() not supported");}
	virtual bool update(vector<ConstantSP>& values, const ConstantSP& indexSP, vector<string>& colNames, string& errMsg) = 0;
	virtual bool append(vector<ConstantSP>& values, INDEX& insertedRows, string& errMsg) = 0;
	virtual bool remove(const ConstantSP& indexSP, string& errMsg) = 0;
	virtual bool upsert(vector<ConstantSP>& values, bool ignoreNull, INDEX& insertedRows, string& errMsg) {throw RuntimeException("Table::upsert() not supported");}
	virtual DATA_TYPE getType() const {return DT_DICTIONARY;}
	virtual DATA_TYPE getRawType() const {return DT_DICTIONARY;}
	virtual DATA_CATEGORY getCategory() const {return MIXED;}
	virtual bool isDistributedTable() const {return false;}
	virtual bool isSegmentedTable() const {return false;}
	virtual bool isDimensionalTable() const {return false;}
	virtual bool isBasicTable() const {return false;}
	virtual bool isDFSTable() const {return false;}
	virtual bool isAppendable() const {return false;}
	virtual bool isEditable() const {return false;}
	virtual bool isSchemaEditable() const {return false;}
	virtual DomainSP getGlobalDomain() const {return DomainSP();}
	virtual DomainSP getLocalDomain() const {return DomainSP();}
	virtual int getGlobalPartitionColumnIndex() const {return -1;}
	virtual int getLocalPartitionColumnIndex(int dim) const {return -1;}
	virtual void setGlobalPartition(const DomainSP& domain, const string& partitionColumn){throw RuntimeException("Table::setGlobalPartition() not supported");}
	virtual bool isLargeConstant() const {return true;}
	virtual bool addSubscriber(const TableUpdateQueueSP& queue, const string& topic, bool local, long long offset = -1, const ObjectSP& filter = 0) { return false;}
	virtual bool removeSubscriber(const TableUpdateQueueSP& queue, const string& topic) { return false;}
	virtual bool subscriberExists(const TableUpdateQueueSP& queue, const string& topic) const { return false;}
	virtual void release() const {}
	virtual void checkout() const {}
	virtual TableSP getSegment(Heap* heap, const DomainPartitionSP& partition, PartitionGuard* guard = 0) { throw RuntimeException("Table::getSegment() not supported");}
	virtual const TableSP& getEmptySegment() const { throw RuntimeException("Table::getEmptySegment() not supported");}
	virtual bool segmentExists(const DomainPartitionSP& partition) const { throw RuntimeException("Table::segmentExists() not supported");}
	virtual long long getAllocatedMemory() const = 0;
	virtual ConstantSP retrieveMessage(long long offset, int length, bool msgAsTable, const ObjectSP& filter, long long& messageId) { throw RuntimeException("Table::retrieveMessage() not supported"); }
	virtual bool snapshotIsolate() const { return false;}
	virtual void getSnapshot(TableSP& copy) const {}
	virtual bool readPermitted(const AuthenticatedUserSP& user) const {return true;}
	virtual bool isExpired() const { return flag_ & 8;}
	virtual void transferAsString(bool option){throw RuntimeException("Table::transferAsString() not supported");}
	virtual int getKeyColumnCount() const { return 0;}
	virtual int getKeyColumnIndex(int index) const { throw RuntimeException("Table::getKeyColumnIndex() not supported");}
	virtual string getChunkPath() const { return "";}
	virtual void share(){};
	inline bool isSharedTable() const {return flag_ & 1;}
	inline bool isRealtimeTable() const {return flag_ & 2;}
	inline bool isAliasTable() const {return flag_ & 4;}
	inline const string& getOwner() const {return owner_;}
	inline void setOwner(const string& owner){ owner_ = owner;}
	void setSharedTable(bool option);
	void setRealtimeTable(bool option);
	void setAliasTable(bool option);
	void setExpired(bool option);
	inline Mutex* getLock() const { return lock_;}

private:
	/*
	 * BIT0: shared table
	 * BIT1: stream table
	 * BIT2: alias table
	 * BIT3: expired
	 */
	char flag_;
	string owner_;
	Mutex* lock_;
};

class DFSChunkMeta : public Constant{
public:
	DFSChunkMeta(const string& path, const Guid& id, int version, int size, CHUNK_TYPE chunkType, const vector<string>& sites, long long cid);
	DFSChunkMeta(const string& path, const Guid& id, int version, int size, CHUNK_TYPE chunkType, const string* sites, int siteCount, long long cid);
	DFSChunkMeta(const DataInputStreamSP& in);
	virtual ~DFSChunkMeta();
	virtual IO_ERR serialize(const ByteArrayCodeBufferSP& buffer) const;
	virtual int size() const {return size_;}
	virtual string getString() const;
	virtual long long getAllocatedMemory() const;
	virtual ConstantSP getMember(const ConstantSP& key) const;
	virtual ConstantSP get(const ConstantSP& index) const {return getMember(index);}
	virtual ConstantSP keys() const;
	virtual ConstantSP values() const;
	virtual DATA_TYPE getType() const {return DT_DICTIONARY;}
	virtual DATA_TYPE getRawType() const {return DT_DICTIONARY;}
	virtual DATA_CATEGORY getCategory() const {return MIXED;}
	virtual ConstantSP getInstance() const {return getValue();}
	virtual ConstantSP getValue() const {return new DFSChunkMeta(path_, id_, version_, size_, (CHUNK_TYPE)type_, sites_, replicaCount_, cid_);}
	inline const string& getPath() const {return path_;}
	inline const Guid& getId() const {return id_;}
	inline long long getCommitId() const {return cid_;}
	inline void setCommitId(long long cid) { cid_ = cid;}
	inline int getVersion() const {return version_;}
	inline void setVersion(int version){version_ = version;}
	inline void setSize(int size){size_ = size;}
	inline int getCopyCount() const {return replicaCount_;}
	bool addCopySite(const string& siteAlias);
	inline const string& getCopySite(int index) const {return sites_[index];}
	inline bool isTablet() const { return type_ == TABLET_CHUNK;}
	inline bool isFileBlock() const { return type_ == FILE_CHUNK;}
	inline bool isSplittable() const { return type_ == SPLIT_TABLET_CHUNK;}
	inline bool isSmallFileBlock() const {return type_ == SMALLFILE_CHUNK;}
	inline CHUNK_TYPE getChunkType() const {return (CHUNK_TYPE)type_;}

protected:
	ConstantSP getAttribute(const string& attr) const;
	ConstantSP getSiteVector() const;

private:
	char type_;
	unsigned char replicaCount_;
	int version_;
	int size_;
	string* sites_;
	string path_;
	long long cid_;
	Guid id_;
};

class Param{
public:
	Param(const string& name, bool readOnly, const ConstantSP& defaultValue = nullptr):
		name_(name),readOnly_(readOnly),meta_(-1), defaultValue_(defaultValue){}
	Param(Session* session, const DataInputStreamSP& in);
	const string& getName() const {return name_;}
	bool isReadOnly() const{return readOnly_;}
	DATA_TYPE getType() const;
	DATA_TYPE getKeyType() const;
	DATA_FORM getForm() const;
	void setMeta(DATA_FORM form, DATA_TYPE type, DATA_TYPE keyType);
	ConstantSP getDefaultValue() const { return defaultValue_;}
	inline bool isDefaultSet() const { return !defaultValue_.isNull() && ! defaultValue_->isNothing();}
	IO_ERR serialize(const ByteArrayCodeBufferSP& buffer) const;
	string getScript(int indention) const;
private:
	string name_;
	bool readOnly_;
	int meta_;
	ConstantSP defaultValue_;
};

class FunctionDef : public Constant{
public:
	FunctionDef(FUNCTIONDEF_TYPE defType, const string& name, const vector<ParamSP>& params, bool hasReturnValue=true, bool aggregation=false, bool sequential=false);
	FunctionDef(FUNCTIONDEF_TYPE defType, const string& name, int minParamNum, int maxParamNum, bool hasReturnValue, bool aggregation=false, bool sequential=false);
	inline const string& getName() const { return name_;}
	inline const string& getModule() const { return module_;}
	inline string getFullName() const { return module_.empty() ? name_ : module_ + "::" + name_;}
	inline void setSyntax(const string& syntax){ syntax_ = syntax;}
	string getSyntax() const;
	inline void setModule(const string& module) { module_ = module;}
	inline bool hasReturnValue() const {return flag_ & 1;}
	inline bool isAggregatedFunction() const {	return flag_ & 2;}
	inline bool isAggregatedFunction(int args) const {	return (flag_ & 2) && (argCountForAgg_ == 0 || args == (int)argCountForAgg_);}
	inline void setArgCountForAggregation(int args) { argCountForAgg_ = args;}
	inline bool supportReturnMeta() const {	return flag_ & 64;}
	inline bool allConstantParameters() const { return flag_ & 4;}
	inline bool bySystemUser() const { return flag_ & 8;}
	inline void bySystemUser(bool option) { if(option) flag_ |= 8; else flag_ &= ~8;}
	inline bool isView() const { return flag_ & 16;}
	inline void setView(bool option) {if(option) flag_ |= 16; else flag_ &= ~16;}
	inline bool isInternal() const { return flag_ & 32;}
	inline void setInternal(bool option) {if(option) flag_ |= 32; else flag_ &= ~32;}
	inline bool isPrivate() const { return extraFlag_ & 1;}
	inline void setPrivate(bool option) {if(option) extraFlag_ |= 1; else extraFlag_ &= ~1;}
	inline bool isProtected() const { return extraFlag_ & 2;}
	inline void setProtected(bool option) {if(option) extraFlag_ |= 2; else extraFlag_ &= ~2;}
	inline bool isJIT() const { return extraFlag_ & 4;}
	inline void setJIT(bool option) {if(option) extraFlag_ |= 4; else extraFlag_ &= ~4;}
	inline bool isSequentialFunction() const { return extraFlag_ & 8;}
	inline void setScalarFunction(bool option){ if(option) extraFlag_ |= 16; else extraFlag_ &= ~16;}
	inline bool isScalarFunction() const { return extraFlag_ & 16;}
	inline void setHigherOrderFunction(bool option){ if(option) extraFlag_ |= 32; else extraFlag_ &= ~32;}
	inline bool isHigherOrderFunction() const { return extraFlag_ & 32;}
	inline bool variableParamNum() const {	return minParamNum_<maxParamNum_;}
	inline int getMaxParamCount() const { return maxParamNum_;}
	inline int getMinParamCount() const {	return minParamNum_;}
	inline bool acceptParamCount(int count) const { return minParamNum_ <= count && maxParamNum_ >= count;}
	inline int getParamCount() const {return minParamNum_;}
	const ParamSP& getParam(int index) const;
	inline bool isUserDefined() const {return defType_ == USERDEFFUNC;}
	inline bool isSystemFunction() const {return defType_ == SYSFUNC;}
	inline FUNCTIONDEF_TYPE getFunctionDefType() const {return defType_;}
	inline unsigned char getFlag() const { return flag_;}
	inline unsigned short getExtraFlag() const { return extraFlag_;}
	DATA_TYPE getReturnType() const;
	DATA_TYPE getReturnKeyType() const;
	DATA_FORM getReturnForm() const;
	void setReturnMeta(DATA_FORM form, DATA_TYPE type, DATA_TYPE keyType);
	inline int getReturnMeta() const { return returnMeta_;}
	void checkArgumentSize(int actualArgCount);
	virtual bool copyable() const {return false;}
	virtual DATA_TYPE getType() const {return DT_FUNCTIONDEF;}
	virtual DATA_TYPE getRawType() const { return DT_STRING;}
	virtual DATA_CATEGORY getCategory() const {return SYSTEM;}
	virtual string getScript() const {return name_;}
	virtual string getString() const {return name_;}
	virtual IO_ERR serialize(Heap* pHeap, const ByteArrayCodeBufferSP& buffer) const = 0;
	virtual FunctionDefSP materializeFunctionDef(Heap* pHeap) { return FunctionDefSP();}
	virtual ConstantSP call(Heap* pHeap, vector<ConstantSP>& arguments) = 0;
	virtual ConstantSP call(Heap* pHeap, const ConstantSP& a, const ConstantSP& b) = 0;
	virtual ConstantSP call(Heap* pHeap,vector<ObjectSP>& arguments) = 0;
	virtual bool containNotMarshallableObject() const {return defType_ >= USERDEFFUNC ;}

protected:
	void setConstantParameterFlag();
	void setReturnValueFlag(bool val);
	void setAggregationFlag(bool val);
	void setSequentialFlag(bool val);

protected:
	static ParamSP constParam_;

	FUNCTIONDEF_TYPE defType_;
	string name_;
	string module_;
	string syntax_;
	vector<ParamSP> params_;
	int minParamNum_;
	int maxParamNum_;
	/**
	 * Some built-in functions such as min and max have multiple signatures. However,
	 * only one of them is an aggregate function. The attribute argCountForAgg_
	 * records the number of argument when it is an aggregate function.
	 */
	unsigned char argCountForAgg_;
	unsigned char flag_;
	unsigned short extraFlag_;
	int returnMeta_;
};

class SQLTransaction {
public:
	TableSP snapshot(Table* table) const;
	bool addTable(Table* table, const TableSP& snapshot);
	void clear();

private:
	vector<pair<Table*, TableSP>> snapshots_;
	mutable Mutex mutex_;
};

class SQLContext{
public:
	SQLContext();
	SQLContext(const SQLTransactionSP& trans);
	void setTable(const TableSP& table);
	void setFilter(const ConstantSP& filter);
	SQLTransactionSP getTransaction() const { return transSP_;}
	TableSP getTable() const{return tableSP_;}
	ConstantSP getFilter() const{return filterSP_;}
	ConstantSP getColumn(const string& qualifier, const string& name);
	ConstantSP getColumn(const string& name);
	void cacheColumn(const string& name,const ConstantSP& col);
	void enableCache();
	void disableCache(){cache_=false;}
	void clear();
	inline bool isInitialized() const { return !tableSP_.isNull();}
	inline bool isNotInitialized() const { return tableSP_.isNull();}

private:
	TableSP tableSP_;
	ConstantSP filterSP_;
	bool cache_;
	DictionarySP cachedCols_;
	SQLTransactionSP transSP_;
};

class ColumnRef: public Object{
public:
	ColumnRef(const SQLContextSP& contextSP, const string& name):contextSP_(contextSP),name_(name),index_(-1),acceptFunctionDef_(true){}
	ColumnRef(const SQLContextSP& contextSP, const string& qualifier, const string& name):contextSP_(contextSP),
			qualifier_(qualifier),name_(name),index_(-1),acceptFunctionDef_(true){}
	ColumnRef(const SQLContextSP& contextSP, const string& name, int index):contextSP_(contextSP),name_(name),index_(index),acceptFunctionDef_(true){}
	ColumnRef(const SQLContextSP& contextSP, const string& qualifier, const string& name, int index):contextSP_(contextSP),
				qualifier_(qualifier),name_(name),index_(index),acceptFunctionDef_(true){}
	ColumnRef(const SQLContextSP& context, const DataInputStreamSP& in);
	virtual ~ColumnRef(){}
	virtual ConstantSP getValue(Heap* pHeap);
	virtual ConstantSP getReference(Heap* pHeap);
	virtual OBJECT_TYPE getObjectType() const {return COLUMN;}
	const string& getQualifier() const { return qualifier_;}
	const string& getName() const { return name_;}
	string getFullname() const { return qualifier_.empty()? name_: qualifier_+"."+name_;}
	int getIndex() const { return index_;}
	DATA_TYPE getType() const;
	int getPartitionDimension() const;
	void setPartitionColumn(DATA_TYPE type, int dimensionIndex);
	void setAcceptFunctionDef(bool option) { acceptFunctionDef_ = option;}
	bool acceptFunctionDef() const { return acceptFunctionDef_;}
	virtual string getScript() const;
	string getNormalizedScript() const;
	virtual IO_ERR serialize(Heap* pHeap, const ByteArrayCodeBufferSP& buffer) const;
	ColumnRef* copy(const SQLContextSP& contextSP) const{ return new ColumnRef(contextSP, qualifier_, name_, index_);}
	ColumnRef* localize(const SQLContextSP& contextSP) const{ return new ColumnRef(contextSP, qualifier_, name_);}
	ColumnRef* localize() const{ return new ColumnRef(contextSP_, qualifier_, name_);}
	bool operator ==(const ColumnRef& target);
	virtual void collectVariables(vector<int>& vars, int minIndex, int maxIndex) const { if(index_<=maxIndex && index_>=minIndex) vars.push_back(index_);}

private:
	SQLContextSP contextSP_;
	string qualifier_;
	string name_;
	int index_;
	bool acceptFunctionDef_;
};

class Operator{
public:
	Operator(int priority, bool unary): priority_(priority), unary_(unary){}
	virtual ~Operator(){}
	int getPriority() const {return priority_;}
	bool isUnary() const {return unary_;}
	virtual ConstantSP evaluate(Heap* heap, const ConstantSP& a, const ConstantSP& b) = 0;
	virtual const string& getName() const = 0;
	virtual string getOperatorSymbol() const  = 0;
	virtual string getTemplateSymbol() const = 0;
	virtual bool isPrimitiveOperator() const = 0;
	virtual IO_ERR serialize(Heap* pHeap, const ByteArrayCodeBufferSP& buffer) const = 0;
	virtual void collectUserDefinedFunctions(unordered_map<string,FunctionDef*>& functionDefs) const = 0;

private:
	int priority_;
	bool unary_;
};

class Output {
public:
	virtual bool timeElapsed(long long nanoSeconds) = 0;
	virtual bool write(const ConstantSP& obj) = 0;
	virtual bool message(const string& msg) = 0;
	virtual void enableIntermediateMessage(bool enabled) = 0;
	virtual bool start() = 0;
	virtual bool start(const string& message) = 0;
	virtual IO_ERR done()=0;
	virtual IO_ERR done(const string& errMsg) = 0;
	virtual IO_ERR writeReady() = 0;
	virtual ~Output(){};
	virtual void close() = 0;
	virtual OUTPUT_TYPE getOutputType() const = 0;
	virtual void setWindow(INDEX offset, INDEX size) = 0;
	virtual IO_ERR flush() = 0;
};

class Session {
public:
	Session(const HeapSP& heap);
	Session(const HeapSP& heap, bool systemSession);
	virtual ~Session(){}
	virtual SessionSP copy(bool forComputing = false) = 0;
	virtual bool run(const vector<string>& source, const string& currentPath = "", int firstLine = 0)=0;
	virtual bool run(const string& scriptFile)=0;
	virtual bool run(const ObjectSP& script)=0;
	virtual bool run(const string& function, vector<ConstantSP>& params)=0;
	virtual bool run(const FunctionDefSP& function, vector<ConstantSP>& params)=0;
	virtual bool run(const vector<string>& variables, vector<ConstantSP>& params)=0;
	virtual bool test(const string& scriptFile, const string& resultFile, bool testMemoryLeaking)=0;
	virtual FunctionDefSP parseFunctionDef(const string& script) = 0;
	virtual bool contain(const string& key) const =0;
	virtual ConstantSP get(const string& key) const=0;
	virtual vector<pair<string,ConstantSP>> getAll() const=0;
	virtual void set(const string& key, const ConstantSP& value, bool copyIfDifferent = false)=0;
	virtual long long getLastActiveTime()=0;
	OutputSP getOutput() const { return out_;}
	void setOutput(const OutputSP& out) {out_ = out;}
	long long getSessionID() const {return sessionID_;}
	void setSessionID(long long sessionID){sessionID_=sessionID;}
	AuthenticatedUserSP getUser();
	AuthenticatedUserSP getUserAsIs();
	bool setUser(const AuthenticatedUserSP& user);
	const string& getRemoteSiteAlias() const { return remoteSiteAlias_;}
	void setRemoteSiteAlias(const string& alias){ remoteSiteAlias_ = alias;}
	int getRemoteSiteIndex() const { return remoteSiteIndex_;}
	void setRemoteSiteIndex(int siteIndex) { remoteSiteIndex_ = siteIndex;}
	const string& getRemoteIP() const { return remoteIP_;}
	void setRemoteIP(const string& ip){ remoteIP_ = ip;}
	int getRemotePort() const { return remotePort_;}
	void setRemotePort(int port) { remotePort_ = port;}
	HeapSP getHeap() const {return heap_;}
	bool isSystemSession() const {return flag_ & 1;}
	void setSystemSession(bool option) { if(option) flag_ |= 1; else flag_ &= ~1;}
	bool isWithinThreadCall() const { return flag_ & 2;}
	void setWithinThreadCall(bool option){ if(option) flag_ |= 2; else flag_ &= ~2;}
	bool isCancelled() const { return flag_ & 4;}
	void setCancelled(bool option){ if(option) flag_ |= 4; else flag_ &= ~4;}
	bool isAPIClient() const { return flag_ & 32;}
	void setAPIClient(bool option){ if(option) flag_ |= 32; else flag_ &= ~32;}
	int getFlag() const { return flag_;}
	bool setFlag(int flag);
	inline void setJobId(const Guid& jobId);
	inline const Guid& getJobId() const { return jobId_;}
	inline void setRootJobId(const Guid& rootJobId) { rootJobId_ = rootJobId;}
	inline const Guid& getRootJobId() const { return rootJobId_;}
	inline void setPriority(int priority) { priority_ = priority;}
	inline int getPriority() const { return priority_;}
	inline void setParallelism(int parallelism) { parallelism_ = parallelism;}
	inline int getParallelism() const { return parallelism_;}
	void setJob(const Guid& rootJobId, const Guid& jobId, int priority, int parallelism);
	virtual SysFunc getTableJoiner(const string& name) const = 0;
	virtual FunctionDefSP getFunctionDef(const string& name) const = 0;
	virtual FunctionDefSP getFunctionView(const string& name) const = 0;
	virtual TemplateOptr getTemplateOperator(const string& name) const = 0;
	virtual TemplateUserOptr getTemplateUserOperator(const string& name) const = 0;
	virtual OptrFunc getOperator(const string& optrSymbol, bool unary, const string& templateName) const = 0;
	virtual OperatorSP getOperator(const FunctionDefSP& func, bool unary) const = 0;
	virtual bool addPluginFunction(const FunctionDefSP& funcDef) = 0;
	virtual void addFunctionDeclaration(FunctionDefSP& func) = 0;
	virtual void addFunctionalView(const FunctionDefSP& funcDef) = 0;
	virtual bool removeFunctionalView(const string& name) = 0;
	virtual void completePendingFunctions(bool commit) = 0;
	virtual void getFunctions(vector<pair<string,FunctionDefSP> >& functions) = 0;
	virtual void undefine(const string& objectName, OBJECT_TYPE objectType, void* objAddr = 0) = 0;
	virtual bool isEnum(const string& word, int& value) const = 0;
	virtual bool isDebugMode() const  = 0;
	virtual void setDebugContext(const DebugContextSP& context) = 0;
	virtual DebugContext* getDebugContext() const  = 0;
	virtual string getCurrentModule() const = 0;
	virtual void pushTemporaryObject(const ConstantSP& obj) = 0;
	virtual ConstantSP getTemoraryObject(int index) = 0;
	virtual void clearTemporaryObject() = 0;
	virtual string getLastErrorMessage() const = 0;
	virtual void* getPrivateKey() const = 0;
	virtual void setPrivateKey(void* key) = 0;

protected:
	long long sessionID_;
	HeapSP heap_;
	OutputSP out_;
	AuthenticatedUserSP user_;
	string remoteIP_;
	int remotePort_;
	string remoteSiteAlias_;
	int remoteSiteIndex_;
	Guid rootJobId_;
	Guid jobId_;
	int priority_;
	int parallelism_;
	int flag_;
};

class Console {
public:
	Console(const SessionSP& session, const OutputSP& out);
	virtual ~Console(){}
	virtual void cancel(bool running){}
	Output* getOutput(){return out_.get();}
	SessionSP getSession(){return session_;}
	long long getLastActiveTime() const { return lastActiveTime_;}
	void setLastActiveTime(long long lastUpdate) { lastActiveTime_ = lastUpdate;}
	inline void setJobId(const Guid& jobId);
	inline const Guid& getJobId() const { return jobId_;}
	inline const Guid& getTaskId() const { return jobId_;}
	inline void setRootJobId(const Guid& rootJobId) { rootJobId_ = rootJobId;}
	inline const Guid& getRootJobId() const { return rootJobId_;}
	inline void setPriority(int priority) { priority_ = priority;}
	inline int getPriority() const { return priority_;}
	inline void setParallelism(int parallelism) { parallelism_ = parallelism;}
	inline int getParallelism() const { return parallelism_;}
	inline bool isCancellable() const {return cancellable_;}
	inline void setCancellable(bool option){cancellable_ = option;}
	void set(const Guid& rootJobId, const Guid& jobId, int parallelism, int priority);
	inline void setFlag(long long flag) { flag_ = flag;}
	inline long long getFlag() const { return flag_;}
	inline bool isUrgent() const { return flag_ & 1;}
	inline bool isSecondaryJob() const { return flag_ & 2;}
	inline bool hasAsynTask() const { return flag_ & 4;}
	inline bool isPickle() const { return flag_ & 8;}
	inline bool isStateless() const { return flag_ & 16;}
	inline bool isAPIClient() const { return flag_ & 32;}
	inline bool compressOutput() const { return flag_ & 64;}
	virtual IO_ERR readReady()=0;
	virtual IO_ERR execute()=0;
	virtual CONSOLE_TYPE getConsoleType() const = 0;
	virtual void run() = 0;
	virtual void getTaskDesc(string& type, string& desc) const = 0;

protected:
	Guid rootJobId_;
	Guid jobId_;
	int priority_;
	int parallelism_;
	bool cancellable_;
	SessionSP session_;
	OutputSP out_;
	long long lastActiveTime_;
	/**
	 * bit0: 0: normal request, 1:urgent request
	 * bit1: 0: normal job, 1:secondary job
	 * bit2: 0: sync request, 1: async request
	 * bit3: 0: inhouse protocol, 1: pickle protocol
	 * bit4: 0: state, 1:stateless (clear session variables upon completion of request)
	 * bit5: 0: normal, 1:optimize for api client
	 * bit6: 0: no compression, 1: compress the output
	 */
	long long flag_;
};

class ConstantMarshall {
public:
	virtual ~ConstantMarshall(){}
	virtual bool start(const ConstantSP& target, bool blocking, IO_ERR& ret)=0;
	virtual bool start(const char* requestHeader, size_t headerSize, const ConstantSP& target, bool blocking, IO_ERR& ret)=0;
	virtual bool resume(IO_ERR& ret)=0;
	virtual void reset() = 0;
	virtual IO_ERR flush() = 0;
};

class ConstantUnmarshall{
public:
	virtual ~ConstantUnmarshall(){}
	virtual bool start(short flag, bool blocking, IO_ERR& ret)=0;
	virtual bool resume(IO_ERR& ret)=0;
	virtual void reset() = 0;
	ConstantSP getConstant(){return obj_;}

protected:
	ConstantSP obj_;
};

class DebugContext{
public:
	DebugContext();
	void waitForExecution(Heap* pHeap, Statement* pStatement);
	void waitForStop();
	void continueExecution(int steps);
	void decreaseSteps();
	int getSteps() const { return steps_;}
	bool continueFlag() const { return continueFlag_;}

private:
	int steps_;
	bool continueFlag_;
	bool stopped_;
	Mutex mutex_;
	ConditionalVariable execCondition_;
	ConditionalVariable stopCondition_;
	Heap* lastHeap_;
	Statement* lastStatement_;
};

class Heap{
public:
	Heap():meta_(0), session_(0), size_(0), status_(0){}
	Heap(Session* session);
	Heap(int size, Session* session);
	~Heap();

	ConstantSP getValue(int index) const;
	const ConstantSP& getReference(int index) const;
	ConstantSP getReference(const string& name) const;
	inline int size() const {return size_;}
	inline bool isViewMode() const { return status_ & 1;}
	inline void setViewMode(bool enabled = true) { if(enabled) status_ |= 1; else status_ &= ~1;}
	inline bool isDefMode() const { return status_ & 2;}
	inline void setDefMode() { status_ |= 2; }
	int getIndex(const string& name) const;
	int getLocalIndex(const string& name) const;
	string getName(int index) const;
	bool contains(const string& name) const;
	int addItem(const string& name, const ConstantSP& value){ return addItem(name, value, false);}
	int addItem(const string& name, const ConstantSP& value, bool constant);
	void removeItem(const string& name);
	void removeAllItems();
	bool set(unsigned int index,const ConstantSP& value, bool constant);
	bool set(unsigned int index,const ConstantSP& value);
	void setConstant(int index, bool constant);
	inline bool isConstant(int index) const {return index>= MAX_SHARED_OBJ_INDEX && (flags_[index - MAX_SHARED_OBJ_INDEX] & 1);}
	inline bool isInitialized(int index) const {return index>= MAX_SHARED_OBJ_INDEX ? flags_[index - MAX_SHARED_OBJ_INDEX] & 2 : true;}
	inline bool isMetaInitalized() const { return meta_ != nullptr;}
	bool isSameObject(int index, Constant* obj) const;
	void rollback();
	void reset();
	void clearFlags();
	void currentSession(Session* session){session_=session;}
	Session* currentSession(){return session_;}
	long long getAllocatedMemory();

private:
	struct HeapMeta{
		Mutex mutex_;
		unordered_map<string,int> nameHash_;
		vector<string> names_;
	};
	HeapMeta* meta_;
	vector<ConstantSP> values_;
	vector<char> flags_;
	Session* session_;
	int size_;
	char status_;
};

struct JITCfgNode {
	JITCfgNode() : visited_(false){}
	string getInferredTypeCacheAsString() const {
		string out = "{";
			for (auto kv: inferredTypeCache) {
				out.append(kv.first + ": " +kv.second.getString() + ", ");
			}
		out.append("}");
		return out;
	}

	// control flow graph: next block edge
	vector<StatementSP> cfgNexts;
	// control flow graph: reverse edge to incoming block
	vector<StatementSP> cfgFroms;
	unordered_map<string, InferredType> inferredTypeCache;
	unordered_map<string, vector<InferredType>> upstreamTypes;
	bool visited_;
};

class StatementContext {
public:
	StatementContext() : status_(0){}
	inline bool shouldReturn() const { return status_ & 1;}
	inline bool shouldBreak() const { return status_ & 2;}
	inline bool shouldContinue() const { return status_ & 4;}
	inline bool shouldBreakOrContinue() const { return status_ & 6;}
	inline bool shouldBreakOrReturn() const { return status_ & 3;}
	inline bool shouldStop() const { return status_ & 7;}
	inline void setReturn() { status_ |= 1;}
	inline void setBreak() { status_ |= 2;}
	inline void setContinue() { status_ |= 4;}
	inline void reset() { status_ = 0;}
	inline void resetBreakContinue() { status_ &= 1;}

private:
	int status_;
};

class Statement{
public:
	Statement(STATEMENT_TYPE type):breakpoint_(false), jitudfHeader_(nullptr), type_(type){}
	virtual ~Statement(){}
	virtual StatementSP clone() = 0;
	STATEMENT_TYPE getType() const {return type_;}
	virtual void execute(Heap* pHeap, StatementContext& context)=0;
	virtual void execute(Heap* pHeap, StatementContext& context, DebugContext* debugContext);
	virtual string getScript(int indention) const = 0;
	virtual IO_ERR serialize(Heap* pHeap, const ByteArrayCodeBufferSP& buffer) const = 0;
	virtual void collectUserDefinedFunctions(unordered_map<string,FunctionDef*>& functionDefs) const {}
	void disableBreakpoint();
	void enableBreakpoint();

    JITCfgNodeSP getCFGNode() const { return cfgNode_; }
    void setCFGNode(const JITCfgNodeSP& cfg) { cfgNode_ = cfg; }
    Statement* getJITUDFHeader() const { return jitudfHeader_;}

    vector<StatementSP>& getCFGNexts();
	vector<StatementSP>& getCFGFroms();
	unordered_map<string, vector<InferredType>> & getUpstreamTypes() { return cfgNode_->upstreamTypes; }
	unordered_map<string, InferredType> & getInferredTypeCache();
	void addCFGNextBlock(const StatementSP& nextBlock);
	void addCFGFromBlock(const StatementSP& fromBlock);
	bool getCFGNodeVisited() const;
	bool setCFGNodeVisited(bool visited = true);
	string getInferredTypeCacheAsString() const;
	virtual IO_ERR buildCFG(const StatementSP& self, std::unordered_map<string, StatementSP> & context);
	virtual string getInferredTypesDebugString(int indention) const;
	virtual void traverseCFG(const StatementSP& self, unordered_set<void*> & visited, CFGTraversalFunc func);
	virtual vector<string> getVarNames() const;
	virtual void setJITUDFHeader(Statement* header);
    void cleanInferredType();

protected:
	bool breakpoint_;
	JITCfgNodeSP cfgNode_;
	Statement* jitudfHeader_;

private:
	STATEMENT_TYPE type_;
};

class StatementFactory {
public:
	virtual ~StatementFactory(){}
	virtual Statement* readStatement(Session* session, const DataInputStreamSP& buffer) = 0;
	virtual Statement* createReturnStatement(const ObjectSP& obj) = 0;
};

class DomainSite{
public:
	DomainSite(const string& host, int port, int index);
	DomainSite(const string& host, int port, int index, const string& alias) ;
	const string& getHost() const {return host_;}
	int getPort() const {return port_;}
	int getIndex() const {return index_;}
	string getString() const;
	const string& getAlias() const {return alias_;}
	inline bool operator ==(const DomainSite& target) const { return  host_ == target.host_ && port_ == target.port_;}
	static DomainSite emptySite_;
private:
	string host_;
	int port_;
	int index_;
	string alias_;
};

class DomainSitePool {
public:
	DomainSitePool() : lastSuccessfulSiteIndex_(-1), lastSiteIndex_(-1), nextSiteIndex_(-1), startSiteIndex_(-1), localSiteIndex_(-1){}
	DomainSitePool(const DomainPartitionSP& partition);
	void addSite(int siteIndex);
	int getLastSite() const;
	inline int getSiteCount() const { return sites_.size();}
	int getSite(int index) const;
	int nextSite() const;
	inline int getNextSite() const { return sites_[nextSiteIndex_].first;}
	inline bool hasNextSite() const { return nextSiteIndex_ >= 0;}
	inline bool containLocalSite() const { return localSiteIndex_ >= 0;}
	void initiateSite(bool useLastSuccessfulSite = false);
	void setIntialSite(int index);
	void resetInitialSite();
	void setLastSuccessfulSite();
	void markUsed(int siteIndex);

private:
	vector<pair<int, bool>> sites_;
	int lastSuccessfulSiteIndex_;
	mutable int lastSiteIndex_;
	mutable int nextSiteIndex_;
	int startSiteIndex_;
	int localSiteIndex_;
};

class DomainPartition{
public:
	DomainPartition(int key, const string& path) : key_(key), version_(0), cid_(-1), path_(path), id_(false), tables_(0){}
	DomainPartition(int key, const string& path, const Guid& id, int version, long long cid) : key_(key), version_(version),cid_(cid), path_(path), id_(id), tables_(0){}
	DomainPartition(int key, const DFSChunkMetaSP& chunkMeta) : key_(key), version_(chunkMeta->getVersion()), cid_(chunkMeta->getCommitId()),
			path_(chunkMeta->getPath()), id_(chunkMeta->getId()), tables_(0){}
	DomainPartition(Session* session, const DataInputStreamSP& in);
	virtual ~DomainPartition();
	const int getKey() const {return key_;}
	virtual bool addSite(int siteIndex) {return false;}
	virtual int getSiteCount() const { return 0;}
	virtual int getSiteIndex(int index) const { throw RuntimeException("DomainPartition::getSiteIndex method not supported.");}
	virtual bool isLocalPartition() const { return true;}
	virtual bool containLocalCopy() const { return true;}
	string getString() const;
	inline const string& getPath() const {return path_;}
	inline const Guid& getId() const {return id_;}
	inline int getVersion() const {return version_;}
	int size(const string& table) const;
	void setSize(const string& table, INDEX size);
	inline long long getCommitId() const { return cid_;}
	inline void setCommitId(long long cid) { cid_ = cid;}
	inline bool operator ==(const DomainPartition& target){ return  (key_ == target.key_) && (id_ == target.id_);}
	IO_ERR serialize(Heap* pHeap, const ByteArrayCodeBufferSP& buffer) const;
	static string processPartitionId(const string& id);
	static ConstantSP parsePartitionId(const string& id, DATA_TYPE type);

private:
	int key_;
	int version_;
	long long cid_;
	string path_;
	Guid id_;

	struct TableSize {
		string name_;
		int size_;
		TableSize* next_;
	};
	TableSize* tables_;
};

struct ClusterNodes {
	const string controllerSite;
	const string controllerAlias;
	const int controllerSiteIndex;
	const vector<int> controllerSiteIndexPool;
	const vector<DomainSite> sites;
	const unordered_map<string, int> sitesMap;

	ClusterNodes(const string& ctrlSite, const string& ctrlAlias) : controllerSite(ctrlSite), controllerAlias(ctrlAlias), controllerSiteIndex(-1){}

	ClusterNodes(const string& ctrlSite, const string& ctrlAlias, int ctrlSiteIndex, const vector<int>& ctrlSiteIndexPool,
			const vector<DomainSite>& nodes, const unordered_map<string, int>& nodesMap) : controllerSite(ctrlSite), controllerAlias(ctrlAlias),
			controllerSiteIndex(ctrlSiteIndex), controllerSiteIndexPool(ctrlSiteIndexPool), sites(nodes), sitesMap(nodesMap){
	}

	void getDataNodeAliases(vector<string>& aliases);
	void getDataNodeIndices(vector<int>& indices);

	inline int getSiteIndex(const string& alias) const {
		unordered_map<string, int>::const_iterator it = sitesMap.find(alias);
		if(it == sitesMap.end())
			return -1;
		else
			return sites[it->second].getIndex();
	}
	inline int getSiteIndex(const string& host, int port) const {
		unordered_map<string, int>::const_iterator it = sitesMap.find(host + ":" + std::to_string(port));
		if(it == sitesMap.end())
			return -1;
		else
			return sites[it->second].getIndex();
	}
	inline const DomainSite& getSite(const string& alias) const {
		unordered_map<string, int>::const_iterator it = sitesMap.find(alias);
		if(it == sitesMap.end())
			return DomainSite::emptySite_;
		else
			return sites[it->second];
	}
	inline const DomainSite& getSite(const string& host, int port) const {
		unordered_map<string, int>::const_iterator it = sitesMap.find(host + ":" + std::to_string(port));
		if(it == sitesMap.end())
			return DomainSite::emptySite_;
		else
			return sites[it->second];
	}
	inline bool isController(int siteIndex) const {
		for(int index : controllerSiteIndexPool){
			if(index == siteIndex)
				return true;
		}
		return false;
	}
};

class ColumnDesc {
public:
	ColumnDesc(const string& name, DATA_TYPE type, int extra, const string& comment = "") : name_(name), comment_(comment), type_(type), extra_(extra){}
	const string& getName() const {return name_;}
	DATA_TYPE getType() const {return type_;}
	int getExtra() const {return extra_;}
	const string& getComment() const { return comment_;}
	void setComment(const string& comment) { comment_ = comment;}

private:
	string name_;
	string comment_;
	DATA_TYPE type_;
	int extra_;
};

class Domain{
public:
	Domain(const string& owner, PARTITION_TYPE partitionType, bool isLocalDomain) : partitionType_(partitionType), isLocalDomain_(isLocalDomain), isExpired_(false),
			retentionPeriod_(-1), retentionDimension_(-1), tzOffset_(INT_MIN), key_(false), owner_(owner){}
	Domain(const string& owner, PARTITION_TYPE partitionType, bool isLocalDomain, const Guid& key) : partitionType_(partitionType), isLocalDomain_(isLocalDomain),
			isExpired_(false), retentionPeriod_(-1), retentionDimension_(-1), tzOffset_(INT_MIN), key_(key), owner_(owner){}
	virtual ~Domain(){}
	int getPartitionCount() const { return partitions_.size();}
	DomainPartitionSP getPartition(int index) const { return partitions_[index];}
	PARTITION_TYPE getPartitionType() const { return partitionType_;}
	bool isLocalDomain() const {return isLocalDomain_;}
	const Guid& getKey() const { return key_;}
	void setKey(const Guid& key) { key_ = key;}
	const string& getName() const { return name_;}
	void setName(const string& name) { name_ = name;}
	const string& getDatabaseDir()const {return dir_;}
	void setDatabaseDir(const string& dir) { dir_ = dir;}
	SymbolBaseManagerSP getSymbolBaseManager() const {return symbaseManager_;}
	void setSymbolBaseManager(const SymbolBaseManagerSP& symbaseManager){ symbaseManager_ = symbaseManager;}
	bool isDFSMode() const;
	virtual ConstantSP getPartitionSites() const { return formatSites(partitions_);}
	virtual ConstantSP getPartitionSchema() const = 0;
	virtual void retrievePartitionsInRange(const ConstantSP& start, bool startInclusive, const ConstantSP& end, bool endInclusive, vector<DomainPartitionSP>& partitions, bool localOnly) const = 0;
	virtual void retrievePartitionsIn(const ConstantSP& values, vector<DomainPartitionSP>& partitions, bool localOnly) const = 0;
	virtual void retrievePartitionAt(const ConstantSP& value, vector<DomainPartitionSP>& partitions, bool localOnly) const = 0;
	virtual void retrieveAllPartitions(vector<DomainPartitionSP>& partitions, bool localOnly) const;
	virtual IO_ERR saveDomain(const string& filename) const;
	virtual IO_ERR saveDomain(const DataOutputStreamSP& out) const = 0;
	virtual ConstantSP getPartitionKey(const ConstantSP& partitionColumn) const = 0;
	virtual bool equals(const DomainSP& domain) const = 0;
	virtual DATA_TYPE getPartitionColumnType(int dimIndex = 0) const = 0;
	virtual int getPartitionDimensions() const { return 1;}
	virtual DomainSP getDimensionalDomain(int dimension) const;
	virtual DomainSP copy() const = 0;
	bool addTable(const string& tableName, const string& owner, vector<ColumnDesc>& cols, vector<int>& partitionColumns);
	bool getTable(const string& tableName, string& owner, vector<ColumnDesc>& cols, vector<int>& partitionColumns) const;
	bool existsTable(const string& tableName);
	bool removeTable(const string& tableName);
	bool listTables(vector<string>& tableNames);
	void loadTables(const string& dir);
	void setExpired(bool option) { isExpired_ = option;}
	inline bool isExpired() const { return isExpired_;}
	inline int getRentionPeriod() const { return retentionPeriod_;}
	inline int getRentionDimension() const { return retentionDimension_;}
	inline int getTimeZoneOffset() const { return tzOffset_;}
	void setRentionPeriod(int retentionPeriod, int retentionDimension, int tzOffset);
	string getOwner() const { return owner_;}
	bool isOwner(const string& owner) const { return owner == owner_;}

	/*
	 * The input arguments set1 and set2 must be sorted by the key value of domain partitions. The ranking of key values must be the same as
	 * the ranking of partition column values when the partition is range-based or value-based.
	 */
	static void set_interaction(const vector<DomainPartitionSP>& set1, const vector<DomainPartitionSP>& set2, vector<DomainPartitionSP>& result);
	static void set_union(const vector<DomainPartitionSP>& set1, const vector<DomainPartitionSP>& set2, vector<DomainPartitionSP>& result);
	static DomainSP loadDomain(const string& domainFile);
	static DomainSP loadDomain(const DataInputStreamSP& in);
	static DomainSP createDomain(const string& owner, PARTITION_TYPE  partitionType, const ConstantSP& scheme);
	static DomainSP createDomain(const string& owner, PARTITION_TYPE  partitionType, const ConstantSP& scheme, const ConstantSP& sites);

protected:
	static VectorSP parseSites(const ConstantSP& sites);
	static ConstantSP formatSites(const vector<DomainPartitionSP>& partitions);
	static bool addSiteToPartitions(const vector<DomainPartitionSP>& partitions, const VectorSP& sites);
	static ConstantSP temporalConvert(const ConstantSP& obj, DATA_TYPE targetType);

protected:
	struct TableHeader {
		TableHeader(){}
		TableHeader(const string& owner, vector<ColumnDesc>& tablesType, vector<int>& tablesPartition): owner_(owner), tablesType_(tablesType), tablesPartition_(tablesPartition){}
		string owner_;
		vector<ColumnDesc> tablesType_;
		vector<int> tablesPartition_;
	};
	vector<DomainPartitionSP> partitions_;
	PARTITION_TYPE partitionType_;
	bool isLocalDomain_;
	bool isExpired_;
	int retentionPeriod_; // in hours
	int retentionDimension_;
	int tzOffset_;
	Guid key_; //the unique identity for this domain
	string name_;
	string dir_;
	string owner_;
	SymbolBaseManagerSP symbaseManager_;
	unordered_map<string, TableHeader> tables_;
	mutable Mutex mutex_;
};

class PartitionGuard {
public:
	PartitionGuard(const TableSP& table);
	PartitionGuard(){}
	~PartitionGuard();
	void setPartition(const TableSP& table);
private:
	TableSP table_;
};

struct TableUpdate{
	TableUpdate(const string& topic, long long offset, int length, int flag, const TableSP& table) : topic_(topic), offset_(offset), length_(length), flag_(flag), filter_(0), table_(table){}
	TableUpdate(const string& topic, long long offset, int length, int flag, const ObjectSP& filter, const TableSP& table) : topic_(topic), offset_(offset), length_(length), flag_(flag), filter_(filter), table_(table){}
	TableUpdate() : offset_(0), length_(0), flag_(0), filter_(0), table_(0){}
	string topic_;
	long long offset_;
	int length_;
	int flag_;
	ObjectSP filter_;
	TableSP table_;
};

struct TableUpdateSizer {
	inline int operator()(const TableUpdate& update){
		return update.table_->getTableType() == LOGROWTBL ? 1 : update.length_;
	}
};

struct TableUpdateUrgency {
	inline bool operator()(const TableUpdate& update){
		return update.flag_ & 1;
	}
};

struct TopicSubscribe {
	TopicSubscribe(const string& topic, int hashValue, vector<string> attributes, const FunctionDefSP& handler, const AuthenticatedUserSP& user,
			bool msgAsTable, int batchSize, int throttleTime, bool persistOffset, bool timeTrigger, bool handlerNeedMsgId) : msgAsTable_(msgAsTable),
			persistOffset_(persistOffset), timeTrigger_(timeTrigger), handlerNeedMsgId_(handlerNeedMsgId), hashValue_(hashValue), batchSize_(batchSize),
			throttleTime_(throttleTime), cumSize_(0), messageId_(-1), expired_(-1), topic_(topic), attributes_(attributes), handler_(handler), user_(user){}
	bool append(long long msgId, const ConstantSP& msg, long long& outMsgId, ConstantSP& outMsg);
	bool getMessage(long long now, long long& outMsgId, ConstantSP& outMsg);
	bool updateSchema(const TableSP& emptyTable);

	const bool msgAsTable_;
	const bool persistOffset_;
	/*
	 * trigger the message handler as long as a fixed time period (specified in throttleTime_) elapses
	 * even if there is no incoming message in the time window when timeTrigger_ is set to true.
	 */
	const bool timeTrigger_;
	/*
	 * if this value is true, the handler accepts two arguments, message body and message id.
	 * Otherwise, the handler accepts only one argument, i.e. message body.
	 */
	const bool handlerNeedMsgId_;
	const int hashValue_;
	const int batchSize_;
	const int throttleTime_; //in millisecond
	int cumSize_;
	std::atomic<long long> messageId_;
	long long expired_;
	const string topic_;
	vector<string> attributes_;
	const FunctionDefSP handler_;
	const AuthenticatedUserSP user_;
	ConstantSP body_;
	ConstantSP filter_;
	Mutex mutex_;
};

class SessionThreadCallGuard {
public:
	SessionThreadCallGuard() : session_(0){}
	SessionThreadCallGuard(Session* session);
	~SessionThreadCallGuard();
	void setThreadCallMode(Session* session);
	void releaseThreadCallMode();

private:
	Session* session_;
};

class ReducerContainer {
public:
	ReducerContainer(Heap* heap, const FunctionDefSP& reducer) : heap_(heap), reducer_(reducer), objCount_(0){}
	bool addObject(const ConstantSP& obj, string& errMsg);
	ConstantSP getResult() const {return result_;}
	int getObjectCount() const {return objCount_;}
	void reset();

private:
	Heap* heap_;
	FunctionDefSP reducer_;
	ConstantSP result_;
	int objCount_;
	Mutex mutex_;
};

class DistributedCall{
public:
	DistributedCall(const ObjectSP& obj, bool local);
	DistributedCall(const ObjectSP& obj, const ReducerContainerSP& reducer, bool local);
	DistributedCall(const ObjectSP& obj, std::function<void (bool, const ConstantSP&)> callback, bool local);
	DistributedCall(const CountDownLatchSP latch, const ObjectSP& obj, bool local);
	DistributedCall(const Guid& jobId, const CountDownLatchSP latch, const ObjectSP& obj, bool local);
	DistributedCall(const Guid& jobId, const CountDownLatchSP latch, const ObjectSP& obj, const ReducerContainerSP& reducer, bool local);
	virtual ~DistributedCall(){}
	virtual void cancel(bool running);
	void getTaskDesc(string& type, string& desc);
	inline void start(){ startTime_ = std::chrono::system_clock::now();}
	inline const ObjectSP& getObject() const { return obj_;}
	inline void setObject(const ObjectSP& obj){obj_ = obj;}
	inline void clearObject(){obj_.clear();}
	inline Heap* getHeap() const { return heap_;}
	inline SessionSP getSession() const {return session_;}
	inline CountDownLatchSP getCountDownLatch() const { return latch_;}
	inline void setCountDownLatch(const CountDownLatchSP& latch){ latch_ = latch;}
	inline void setCarryoverOption(bool option){ carryover_ = option;}
	inline bool getCarryoverOption() const { return carryover_;}
	void setJobId(const Guid& jobId);
	inline const Guid& getJobId() const { return jobId_;}
	inline void setRootJobId(const Guid& rootJobId) { rootJobId_ = rootJobId;}
	inline const Guid& getRootJobId() const { return rootJobId_;}
	inline const Guid& getTaskId() const { return taskId_;}
	inline void setPriority(int priority) { priority_ = priority;}
	inline int getPriority() const { return priority_;}
	inline void setParallelism(int parallelism) { parallelism_ = parallelism;}
	inline int getParallelism() const { return parallelism_;}
	void set(Heap* heap, const SessionSP& session, const Guid& jobId, const CountDownLatchSP& latch);
	void set(Heap* heap, const SessionSP& session);
	void done(const ConstantSP& result);
	void done(const string& errMsg);
	inline const string& getErrorMessage() const {return errMsg_;}
	inline ConstantSP getResultObject() const {return execResult_;}
	inline ConstantSP getCarryoverObject() const {return carryoverResult_;}
	inline bool isLocalData() const { return local_;}
	inline bool isViewMode() const { return viewMode_;}
	inline bool isCancellable() const {return cancellable_;}
	inline void setCancellable(bool option){cancellable_ = option;}
	virtual void setLastSuccessfulSite(){}
	virtual int getLastSite(){return -1;}
	static ConstantSP mergeDistributedCallResult(vector<DistributedCallSP>& calls);

private:
	Guid rootJobId_;
	Guid jobId_;
	Guid taskId_;
	int priority_;
	int parallelism_;
	CountDownLatchSP latch_;
	ObjectSP obj_;
	string errMsg_;
	ConstantSP execResult_;
	ConstantSP carryoverResult_;
	ReducerContainerSP reducer_;
	std::function<void (bool, const ConstantSP&)> callback_;
	std::chrono::system_clock::time_point receivedTime_;
	std::chrono::system_clock::time_point startTime_;
	std::chrono::system_clock::time_point completeTime_;
	bool local_;
	bool viewMode_;
	bool cancellable_;
	bool carryover_ = false;
	bool callbackMode_ = false;
	Heap* heap_;
	SessionSP session_;
};

struct JobProperty {
	JobProperty() : rootId_(false), taskId_(false), priority_(0), parallelism_(1),cancellable_(true) {}
	JobProperty(const Guid& rootId, const Guid& taskId, int priority, int parallelism, bool cancellable) : rootId_(rootId),
			taskId_(taskId), priority_(priority), parallelism_(parallelism), cancellable_(cancellable){}
	JobProperty(const DataInputStreamSP& in);
	IO_ERR serialize(const ByteArrayCodeBufferSP& buffer) const;
	void setJob(const DistributedCallSP& call);

	Guid rootId_;
	Guid taskId_;
	int priority_;
	int parallelism_;
	bool cancellable_;
};

#endif /* CORECONCEPT_H_ */
