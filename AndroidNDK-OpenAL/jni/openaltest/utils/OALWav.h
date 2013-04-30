// OALWav.h
// ������ ��� .wav �����

#include "OALSound.h"


/**
 * ��������� ������ WAV
 */
typedef struct {
  char  riff[4];				// 'RIFF'
  unsigned int riffSize;		// ������ ����� �RIFF�
  char  wave[4];				// 'WAVE'
  char  fmt[4];					// 'fmt '
  unsigned int fmtSize;			// ������ fmt-�����
  unsigned short format; 	    // ������ �������� ������
  unsigned short channels;      // ���������� �������
  unsigned int samplesPerSec;	// ������� ������������� ������������
  unsigned int bytesPerSec;     // ���������� ���� ������������ � �������
  unsigned short blockAlign;    // ������������ ������ � ����� ������
  unsigned short bitsPerSample; // ���������� ��� �� ���� ������� �������
  char  data[4];				// 'data'
  unsigned int dataSize;		// ������ ����� � ������ �������
}BasicWAVEHeader;

class OALWav : public OALSound{
public:
	AAssetFile f;
	OALWav();
	OALWav(bool streaming);
	~OALWav();
	void load(AAssetManager *mgr, const char* filename);
	void play();
	//void setVolume(float volume, int iBuffer);
private:
	/**
	 * ��������� ���� �������.
	 */
	unsigned char* readWAVFull(AAssetManager *mgr, BasicWAVEHeader* header);
	/**
	 * ��������� ����������� ���������� ������
	 */
	unsigned char* readRiffs(int count);
	/**
	 * �������� OpenAL ������
	 */
	void createBufferFromWave(unsigned char* data);
	/**
	 * �������� OpenAL ������ �� ������������ ������� � ������ �������
	 */
	void createBufferFromWave(unsigned char* data, int size, int index);
	void getFormat();
	void GenSources();
	//void GenSources(int index);
	void LogHeaders();
	/**
	 * �������� ������ �� ������������ �������
	 */
	void creatBuffer(int index);

	//unsigned int riffCount;
	//float getOffset();
	BasicWAVEHeader header;
	//AAssetManager *mgr;
	unsigned int curPos;
	//unsigned int riffSize;
	//short currentBuff;

	//int pid;
};
