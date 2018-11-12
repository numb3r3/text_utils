# 文本处理工具脚本库


## 中文断句

[项目](http://git.code.oa.com/singerhe/NewsBrief)使用的中文分句算法支持**普通文本**的句子切分和**嵌套双引号**的句子切分两种形式。

- 支持普通文本的句子切分
普通的文本切分就是直接按照句子断句的标点符号进行切分。当句子中包含双引号标点时，如果双引号中的内容并不包含断句符号，则认为双引号中的内容属于原句成分，也当做普通句子进行切分即可。

- 支持嵌套双引号的句子切分
但当嵌套双引号中内容包括断句标点，则需要分情况考虑。我们定义了一个参数，用于控制引号中单个句子的边际长度。当引号中部分被断句符号切开后，长度小于边际长度时，我们认为这一处断句符号不应切分句子。反之，需要根据断句符号进行切分，并且此时双引号也将被视为断句符号，即上引号前面的部分单独成句，下引号后面的部分单独成句。

**断句使用方法**

```
from segmenter import SentenceSegmenter

text = '据邯郸市教育局今日通报：为进一步落实《河北省教。题的补充。通知。》的文件精神，保证良好的教育发展环境，衡水市第一中学、衡水志臻中学、石家庄二中实验学校等16所外地民办普通高中学校因在邯郸市违规招生，被取消3年内的招生资格。'
ss = SentenceSegmenter()

res = ss.segment(text)
for item in res:
    print(item)

```

## 中文分词

使用Jieba框架，可以自定义词典，停用词。

```
from tokenizer import Tokenizer

tokenizer = Tokenizer()
tokenizer.load()

line = '据邯郸市教育局今日通报'
for token in tokenizer.tokenize(line):
    print(token)
```

**分词使用方法**

```
from tokenizer import Tokenizer

tokenizer = Tokenizer()
tokenizer.load()
```

## 资源文件

- resources/stopwords.txt: 1,897个停用词 (来自多个开源项目的合并)
- resources/punctuation.txt: 71个标点符号

## 鸣谢

- 1. [新闻自动摘要](http://git.code.oa.com/singerhe/NewsBrief)