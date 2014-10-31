/**
@file   xmlconf.h
@brief  ��ȡxml�����ļ���ͷ�ļ�

@author sjij@mail.51.com
@date Begin 2008.3
@date Dnd 2008.3
*/

#ifndef CXMLCONFIG_H_
#define CXMLCONFIG_H_
//#define TIXML_USE_STL

#include <string>
#include <iostream>
#include "tinystr.h"
#include "tinyxml.h"
#include "../common/common_typedef.h"

 
namespace Game51 { namespace Server {

const uint32_t NUM_INDENTS_PER_SPACE = 2;

class CXmlConfig
{
public:
	CXmlConfig();
	explicit CXmlConfig(const char* xmlFileName) 
		:m_XmlConfigFile(xmlFileName),m_RootElem(0) 
	{
		//���������ļ�
		m_XmlConfigFile.LoadFile();  
		//�õ������ļ��ĸ����
		m_RootElem = m_XmlConfigFile.RootElement();
	}

	int Init(const char* xmlFileName);

public:
	/***
	**	@brief���õ��ַ�����������
	**  @param[in]  const std::string& blockName ������
	**	@param[in]  const std::string& nodeName  �ڵ���
	**	@param[in] char* value  ���صĽ��
	**/
	void GetValue(const std::string& blockName, const std::string& nodeName, char *value);

	/***
	**	@brief���õ���������
	**  @param[in]  const std::string& blockName ������
	**	@param[in]  const std::string& nodeName �ڵ���
	**	@param[out] int& value  ���صĽ��
	**  @param[in]  int  defaut Ĭ�ϲ���
	**/	
	void GetValue(const std::string& blockName, const std::string& nodeName, int32_t& value, int defaut = -1);
    
	/***
	**	@brief���õ��ַ�����������
	**	@param[in]  const std::string& nodeName �ڵ���
	**	@param[in] char* value  ���صĽ��
	**/
	void GetValue(const std::string& nodeName, char *value);

	/***
	**	@brief���õ���������
	**	@param[in]  const std::string& nodeName �ڵ���
	**	@param[out] int& value  ���صĽ��
	**  @param[in]  int  defaut Ĭ�ϲ���
	**/	
	void GetValue(const std::string& nodeName, int32_t& value, int defaut = -1);

	//�ض������ļ�
	void ReLoadConfig(const char* xmlFileName);

	//�г�����ѡ��
	void List();
private:
	void dump_to_stdout( TiXmlNode* pParent, uint32_t indent = 0 );
	int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent);
	const char *getIndentAlt( unsigned int numIndents );
	const char *getIndent( unsigned int numIndents );
private:
	TiXmlDocument m_XmlConfigFile;
	TiXmlElement* m_RootElem;
};

}}//namespace Game51 { namespace Server

#endif

