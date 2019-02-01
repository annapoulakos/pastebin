<!DOCTYPE html>
<html>
	<head>
		<title>[[Add your own Title here]]/title>
		
		<link href="//netdna.bootstrapcdn.com/twitter-bootstrap/2.2.1/css/bootstrap-combined.min.css" rel="stylesheet">
		<script src="//ajax.googleapis.com/ajax/libs/angularjs/1.0.2/angular.min.js"></script>
		<script src="//ajax.googleapis.com/ajax/libs/angularjs/1.0.3/angular-resource.min.js"></script>
	</head>
	
	<body ng-app="articleLibraryApp" ng-controller="articleLibraryCtrl">
		<div class="container">
			<div class="row-fluid">
				<div class="span4">
					<!-- Menu Goes Here -->
					<ul class="unstyled">
						<li ng-repeat="category in categories">
							{{category.name}}
							<ul class="unstyled">
								<li ng-repeat="subcategory in category.subcategories">
									{{subcategory.name}}
									<ul class="unstyled">
										<li ng-repeat="article in subcategory.articles">
											<a ng-click="refreshArticle(article.url)" class="act act-primary">
											<i class="iconic-article"></i> 
											{{article.title}}
											</a>
										</li>
									</ul>
								</li>
							</ul>
						</li>
					</ul>
				</div>
				<div class="span8">
					<div id="article" ng-include src="currentSelection"></div>
				</div>
			</div>
		</div>
		<script src="//netdna.bootstrapcdn.com/twitter-bootstrap/2.2.1/js/bootstrap.min.js"></script>
		<script type="text/javascript">
		var articleLibraryApp = angular.module( 'articleLibraryApp', ['ngResource'] );
		
		articleLibraryApp.factory( 'LibraryApi', function($resource){
			return $resource(
				'./library/glob.php', 
				{},
				{}
			);
		});
		function articleLibraryCtrl( $scope, LibraryApi ){
			$scope.categories = LibraryApi.query();
			$scope.currentSelection = '';
			
			$scope.refreshArticle = function ( url ){
				$scope.currentSelection = './library/' + url;
			}
		}
		</script>
	</body>
</html>