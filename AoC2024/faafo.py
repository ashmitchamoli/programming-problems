import torch

n_features = 512
n_outputs = 13
n_samples = 1000

X = torch.randn(n_samples, n_features)
y = torch.randn(n_samples, n_outputs)

model = torch.nn.Sequential(
	torch.nn.Linear(n_features, 128),
	torch.nn.ReLU(),
	torch.nn.Linear(128, 64),
	torch.nn.ReLU(),
	torch.nn.Linear(64, n_outputs)
)
criterion = torch.nn.MSELoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
model.to(device)
X = X.to(device)
y = y.to(device)

while True:
	model.train()
	optimizer.zero_grad()
	y_pred = model(X)
	loss = criterion(y_pred, y)
	loss.backward()
	optimizer.step()