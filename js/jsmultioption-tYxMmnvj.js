	crmAdminApp.factory( 'MappingService', [ 'testApi', function( testApi ){
		var msImport = function(){
			console.log('in import function');
		};

		var me = {
			test: 'Testing',
			selectedItem: {},
			currentItem: {},
			selectList: [{label:'test 1', id: 1}, {label:'test 2', id:2}],
			import: function(){
				console.log('in import function');
			},
			update: function(){
				this.test = 'In update function';
			},
			prepareRemove: function(){
				console.log('in perpareRemove function');
			},
			remove: function(){

			},
			actions: [
				{ method: msImport, label: 'Import CSV' },
				{ method: this.update, label: 'Update Perspective' },
				{ method: this.prepareRemove, label: 'Remove Perspective' }
			],
			onSelectChange: function(){
				this.currentItem = testApi.get({controller:'perspectives', id: this.selectedItem.id});
			}

		};
		return me;
	}]);