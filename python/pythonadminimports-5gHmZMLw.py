from my.models import ModelA, ModelB

class ModelAAdmin():
	pass
admin.site.register(ModelA, ModelAAdmin)

class ModelBAdmin():
	pass
admin.site.register(ModelB, ModelBAdmin)

or

from my.models import ModelA
class ModelAAdmin():
	pass
admin.site.register(ModelA, ModelAAdmin)

from my.models import ModelB
class ModelBAdmin():
	pass
admin.site.register(ModelB, ModelBAdmin)