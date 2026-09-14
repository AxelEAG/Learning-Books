K Nearest Neighbors (KNN) classifies an entity based on what it's closest to.
It does this by calculating the distance (similarity) between the two entities in
N-dimensions (features).

The two main things KNN can do are:
	* Classification: categorization into a group
	* Regression: predicting an outcome / response

To do this comparison, one must convert the items into a vector of features - referred
to as feature extraction. For KNN to be successful, it's important to pick good features:
	* They should directly correlate to the classification.
	* They should not have a bias.

KNN has many applications and is often used in Machine learning. An example is
Optical Character Recognition (OCR) - image to text. It boils down to:
	1. Training: Extract features of a data set
	2. Classifying: Given an image, extract the feature and use the KNN to classify it.

Other applications are a spam filter, which uses an algorithm called Naive Bayes classifier,
and attempting to predict the stock market.

Notes:
Maybe try that as next small project?
Naive Bayes Classifier
Cosine similarity